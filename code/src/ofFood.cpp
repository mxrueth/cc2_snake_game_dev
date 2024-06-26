#include "ofFood.h"


ofFood::ofFood()
:scl{50}, color{250,0,50}
{
    
    
    // set the first position of food randomly
    // otherwise food and snake have the same pos at (0,0) which leads to an error
    // in "snake's eat function > startcheck is increased w/o reason"
    pickLocation();
    
}






void ofFood::pickLocation() {

    int cols = floor(ofGetWidth() / scl);
    int rows = floor(ofGetHeight() / scl);

    pos.x = floor(ofRandom(cols))*scl;
    pos.y = floor(ofRandom(rows))*scl;

    cout << "PICKED " << pos.x << endl;
}


void ofFood::draw() {
    ofSetColor(color.x,color.y,color.z);
    shape();
}


void ofFood::shape() {
    ofDrawRectangle(pos.x, pos.y, scl, scl);
}


glm::vec2 ofFood::getPosition() {
    return pos;
}

