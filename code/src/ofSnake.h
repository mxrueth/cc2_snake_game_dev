#pragma once

#include "ofMain.h"


class ofSnake {

public:

    ofSnake();
    ~ofSnake();
 
    int cellSize = 50;

    ofColor color;

    void update();
    void draw();
    void grow();
    void setDir(int x, int y);
    bool checkCollision();

    void setUpdateInterval(float interval);
    float getUpdateInterval() const;
    void calculateUpdateInterval();

    vector<ofPoint> body;

    private:

    ofPoint direction;
    ofPoint lastTail;
    float lastUpdateTime;
    float updateInterval;


};
