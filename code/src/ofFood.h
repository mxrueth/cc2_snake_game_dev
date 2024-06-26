#pragma once

#include "ofMain.h"


class ofFood {
    
public:

    ofFood();

    virtual ~ofFood() = default;


    void draw();
    virtual void shape();
    void pickLocation();
    
    glm::vec2 getPosition();
  
protected:
    glm::vec3 color;
    glm::vec2 pos;
    int scl;

private:






};
