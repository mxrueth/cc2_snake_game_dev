#pragma once
#include "ofMain.h"
#include <stdio.h>

class vfx {
    
public:
    vfx();
    ~vfx();
    
    void grid();
    void create(vector<ofVec2f>& allVectors, ofPoint headPos);
    void generatePoints();
    
    bool finished;
    
private:
    ofVec2f lastEndVec;
    bool pointsGenerated;    
    bool executedOnce = false;
    int stepper;
    
    vector<ofVec2f> originPoints; //TODO: remove?
    //int stepperMultiplier = 5;
    
};
