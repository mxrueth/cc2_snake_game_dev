#include "ofSnake.h"

float gameSpeed = 0.175f;
//float gameSpeed = 0.1;
//float gameSpeed = 0.05;

ofSnake::ofSnake()
    : updateInterval(gameSpeed), lastUpdateTime(0.0f) {
    direction.set(1, 0);
    body.push_back(ofPoint(0, 0));
    
}

ofSnake::~ofSnake() {
}

void ofSnake::update() {
    float currentTime = ofGetElapsedTimef();

    if (currentTime - lastUpdateTime < updateInterval) {
        return; // Not enough time has passed, so skip this update
    }

    lastUpdateTime = currentTime;

        lastTail = body.back();
        for (int i = body.size() - 1; i > 0; --i) {
            body[i] = body[i - 1];
        }
        body[0] += direction * cellSize;

        body[0].x = (static_cast<int>(body[0].x) + ofGetWidth()) % ofGetWidth();
        body[0].y = (static_cast<int>(body[0].y) + ofGetHeight()) % ofGetHeight();
    
}


void ofSnake::draw() {
    ofSetColor(color);
    int newSize = cellSize * 1.5;

    //for (auto& segment : body) {
        //ofDrawRectangle(segment.x, segment.y, cellSize, cellSize);
    //}

    for (auto it = body.begin() + 1; it != body.end(); ++it) {
        ofDrawRectangle(it->x, it->y, cellSize, cellSize);
    }


    ofPushMatrix();
    ofTranslate(body[0].x + cellSize / 2, body[0].y + cellSize / 2);
    ofRotateDeg(snakeAngle);
    float x1 = 0;
    float y1 = -newSize / 2;    float x2 = -newSize / 2;
    float y2 = newSize / 2;    float x3 = newSize / 2;
    float y3 = newSize / 2;
    ofDrawTriangle(x1, y1, x2, y2, x3, y3); // Dreieck zeichnen
    ofPopMatrix(); // Transformation wiederherstellen

}

ofPoint ofSnake::getPosHead() {
    return body.front();
}

void ofSnake::grow() {
    body.push_back(lastTail);
    calculateUpdateInterval();
}

void ofSnake::setDir(int x, int y) {
    direction.set(x,y);
}

bool ofSnake::checkCollision() {
    ofPoint head = body.front();
    for (int i = 1; i < body.size(); ++i) {
        if (body[i] == head) {
            return true;
        }
    }
    return false;
}

void ofSnake::setUpdateInterval(float interval) {
    if (interval > 0.0f) {
        updateInterval = interval;
    }
}

float ofSnake::getUpdateInterval() const {
    return updateInterval;
}

void ofSnake::calculateUpdateInterval() {
    updateInterval = gameSpeed * exp(-gameSpeed * body.size()); // Exponential decrease, adjust the factor for desired speed
}



void ofSnake::setAngle(int angle) {
    snakeAngle = angle; 
}


