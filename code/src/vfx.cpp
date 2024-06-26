#include "vfx.h"
using namespace std;

vfx::vfx() {
    stepper = 64;
}

vfx::~vfx() {
}

//Here we get two points (each per flash anim) on the grid.
//The first point will be closest to the snake head, the second will be further away
//Each iteration the distance from first to second point gets smaller
//Also we draw a line between them and delete the grid points so they can't be used a second time
void vfx::animate(vector<ofVec2f>& allVectors, ofPoint position){
    
    //GET THE FIRST (OR NEXT) TWO POINTS TO DRAW A LINE
    //as long as the animation is not finsihed
    if(!finished) {
        if(allVectors.size()>0)
        {
            //food or player position
            ofVec2f effectOrigin = position;
            ofVec2f startVec;
            
            //If we haven't executed this block already once before for this instance
            if(!executedOnce){
                //sortiere das array abhaneging vom origin point, thanks AI
                std::sort(allVectors.begin(), allVectors.end(), [&effectOrigin](const ofVec2f& a, const ofVec2f& b) {
                    return a.distance(effectOrigin) < b.distance(effectOrigin);
                });
                //get the first closest point to player
                startVec.x = allVectors[0].x;
                startVec.y = allVectors[0].y;
            }else{
                startVec = lastEndVec;
                stepper -= int(stepper / 2);
                if(stepper <= 1) {
                    finished = true;
                }                
            }
            //damit wir beim zweiten durchlauf hier, nicht den ersten punkt bekommen, nehmen wir ihn raus aus dem spiel
            allVectors.erase(allVectors.begin()); //remove point from array
            
            //We want now the closest point to the new point. So sort array again, starting from that new point
            std::sort(allVectors.begin(), allVectors.end(), [&startVec](const ofVec2f& a, const ofVec2f& b) {
                return a.distance(startVec) < b.distance(startVec);
            });
            //if this is the second time we run through this, then this point will be the closest point to the last end-point, because of the if-else statement above.
            //the stepper goes from big to small quadratically
            ofVec2f endVec(allVectors[stepper].x, allVectors[stepper].y);

            //DRAW
            //verbinden den ersten und Xten punkt mit einer linie
            ofSetColor(250, 50, 50);
            //the stepper decreases the linewidth by half everytime so we start thick and get thin
            ofSetLineWidth(int(stepper/2));
            //if this is the first time we go through this, draw also the line from origin to the next point. Otherwise just draw lines between the two new points
            if(!executedOnce){
                ofDrawLine(effectOrigin.x, effectOrigin.y, startVec.x, startVec.y);
                ofDrawLine(startVec.x, startVec.y, endVec.x, endVec.y);
            }else{
                ofDrawLine(endVec.x, endVec.y, startVec.x, startVec.y);
            }
            //ofDrawLine(100, 100, closestVec.x, closestVec.y);
            
            lastEndVec = endVec;
            executedOnce = true;
        }
    }
}
