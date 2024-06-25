#pragma once
#include "ofMain.h"
#include <stdio.h>

class vfx {
    
public:
    
    vfx();
    ~vfx();
    void grid();
    void create(vector<ofVec2f>& allVectors);
    void draw();
    void generatePoints();
    bool finished;
    
private:
    bool pointsGenerated;
    //bool generatePoints = false;
    int pointsPerClick = 3;
    int counterPointsGenerated;
    //ofVec2f vec;
    ofVec2f vecAtMouse;
    //std::vector<ofVec2f> allpoints;
    ofPolyline line;
    
    
    vector<ofVec2f> originPoints; //TODO: remove?
    
    
    ofVec2f lastEndVec;
    bool executedOnce = false;
    
    int stepper = 52;
    int stepperMultiplier = 5;
    
};
