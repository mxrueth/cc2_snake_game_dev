#include "ofSnake.h"



ofSnake::ofSnake() {

    xSpeed = 0;
    ySpeed = 0;

    int stage = 0;

    colorIO.set(255);
}

ofSnake::~ofSnake() {

    int test = 4;
    std::cout << "help, I will die" << std::endl;

}

void ofSnake::updateSnake() {

    myPos.x = myPos.x + xSpeed * cellSize;
    myPos.y = myPos.y + ySpeed * cellSize;

    //min-max range maped to canvas
    myPos.x = ofClamp(myPos.x, 0, ofGetWidth() - cellSize);
    myPos.y = ofClamp(myPos.y, 0, ofGetHeight() - cellSize);

}

void ofSnake::keyPressed(int key) {
    std::cout << "keypressed: " <<key << std::endl;
    if (key == OF_KEY_UP) {
        direction = UP;
        setDir(0, -1);
    }
    else if (key == OF_KEY_DOWN) {
        direction = DOWN;
        setDir(0, 1);
    }
    else if (key == OF_KEY_LEFT) {
        direction = LEFT;
        setDir(-1, 0);
    }
    else if (key == OF_KEY_RIGHT) {
        direction = RIGHT;
        setDir(1, 0);
    }
    
    std::cout << "direction: " << direction << std::endl;
}

void ofSnake::drawSnake() {
    ofSetColor(colorIO);
    float newSize = cellSize * 2;

    ofPushMatrix(); // Aktuelle Transformation speichern
    ofTranslate(myPos.x + cellSize / 2, myPos.y + cellSize / 2); // Ursprung zur Mitte der Zelle verschieben

    // Winkel basierend auf der Richtung setzen
    float angle = 0;
    switch (direction) {
    case UP:
        angle = 0;
        break;
    case DOWN:
        angle = 180;
        break;
    case LEFT:
        angle = -90;
        break;
    case RIGHT:
        angle = 90;
        break;
    }
    ofRotateDeg(angle); // Drehe das Koordinatensystem

    // Eckpunkte des Dreiecks relativ zur neuen Mitte berechnen
    float x1 = 0;
    float y1 = -newSize / 2;
    float x2 = -newSize / 2;
    float y2 = newSize / 2;
    float x3 = newSize / 2;
    float y3 = newSize / 2;

    ofDrawTriangle(x1, y1, x2, y2, x3, y3); // Dreieck zeichnen

    ofPopMatrix(); // Transformation wiederherstellen
}

void ofSnake::setDir(int x, int y) {
    
    xSpeed = x;
    ySpeed = y;

    
}



bool ofSnake::eat(ofVec2f foodPos) {

    if (myPos.distance(foodPos) < cellSize) {
        
        std::cout << " eat !" << std::endl;

        return true;
    }

    return false;

}
