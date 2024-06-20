#pragma once

#include "ofMain.h"


class ofFood {
    
public:

    ofFood();
    ~ofFood();


    void draw();
    void pickLocation();
    
    ofPoint pos;
    ofColor color;
    int scl = 50;




};
