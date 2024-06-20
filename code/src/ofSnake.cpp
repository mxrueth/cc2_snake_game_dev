#include "ofSnake.h"



ofSnake::ofSnake()
    : updateInterval(0.5f), lastUpdateTime(0.0f) {
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
    for (auto& segment : body) {
        ofDrawRectangle(segment.x, segment.y, cellSize, cellSize);
    }
}

void ofSnake::grow() {
    body.push_back(lastTail);
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
