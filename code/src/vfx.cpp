#include "vfx.h"
using namespace std;

vfx::vfx() {
    stepper = 64;
    //stepperMultiplier = 4;
}

vfx::~vfx() {
}

void vfx::create(vector<ofVec2f>& allVectors, ofPoint headPos){
       
    //get line points close to player and move slowly away
    if(!finished) {
        if(allVectors.size()>0)
        {
            //GET THE FIRST TWO POINTS CLOSE TO PLAYER POS
            //player position
            ofVec2f playerPos = headPos;
            //ofDrawRectangle(playerPos.x, playerPos.y, 3, 3);
            ofVec2f startVec;
            if(!executedOnce){
                //sortiere das array abhaneging vom origin point, thanks AI
                std::sort(allVectors.begin(), allVectors.end(), [&playerPos](const ofVec2f& a, const ofVec2f& b) {
                    return a.distance(playerPos) < b.distance(playerPos);
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
            //originPoints.push_back(closestVec); //save for deletion for later
            
            //damit wir nicht beim naechsten durchlauf nicht den ersten punkt bekommen, nehmen wir ihn raus aus dem spiel
            allVectors.erase(allVectors.begin()); //remove point from array
            
            //sort array again, starting from that new point
            std::sort(allVectors.begin(), allVectors.end(), [&startVec](const ofVec2f& a, const ofVec2f& b) {
                return a.distance(startVec) < b.distance(startVec);
            });
            //now we get the closest point to the point that was closest to the player.
            //if we have been here before then this point will be the closest point to the last end-point
            ofVec2f endVec(allVectors[stepper].x, allVectors[stepper].y);

            //verbinden den ersten und Xten punkt mit einer linie
            ofSetColor(250, 50, 50);
            ofSetLineWidth(int(stepper/5));
            if(!executedOnce){
                ofDrawLine(playerPos.x, playerPos.y, startVec.x, startVec.y);
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
