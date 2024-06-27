#pragma once

#include "ofMain.h"

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};


class ofSnake {

public:

    ofSnake();
    ~ofSnake();

    int foo = 6;

        

    float xSpeed;
    float ySpeed;
    
    int cellSize = 50;

    

    void updateSnake();
    void drawSnake();
    void setDir(int x, int y);
    bool eat(ofVec2f foodPos);

    ofVec2f myPos{ 0,0 };

    int snakeAngle = 0;

    void keyPressed(int key);

    // Attribute
    ofColor colorIO;
   // ofPoint myPos;
    //float cellSize;
    int direction = UP; // Anfangsrichtung

};
