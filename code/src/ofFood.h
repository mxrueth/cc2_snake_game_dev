#pragma once

#include "ofMain.h"


class ofFood {
    
public:

    ofFood();
    ofFood(glm::vec3 _color, int _scl);

    virtual ~ofFood() = default;


    void draw();
    virtual void shape();
    void pickLocation();
    
    glm::vec2 getPosition();
  
protected:
    
    glm::vec2 pos;
    int scl;

private:
    glm::vec3 color;
    




};
