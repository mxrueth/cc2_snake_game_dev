#pragma once
#include "ofMain.h"
#include <stdio.h>

class vfx {
    
public:
    
    vfx();
    ~vfx();
    void spawn();
    void generatePoints();
    
private:
    bool pointsGenerated;
    //bool generatePoints = false;
    int pointsPerClick = 3;
    int counterPointsGenerated;
    //ofVec2f vec;
    ofVec2f vecAtMouse;
    //std::vector<ofVec2f> allpoints;
    ofPolyline line;
    vector<ofVec2f> allVectors;
    vector<ofVec2f> originPoints;
    
};
