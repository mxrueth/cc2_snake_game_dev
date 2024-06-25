#include "vfx.h"

using namespace std;

ofVec2f lastEndVec;
bool executedOnce;
bool finished;
int stepper = 200;

vfx::vfx()
{
    
}

vfx::~vfx()
{
    
}


void vfx::generatePoints()
{

    
        for (int i = 0; i < ofGetWidth(); i= i+25) {
            for (int k = 0; k < ofGetHeight(); k= k+25) {
                float ran1 = ofRandom(100);
                float ran2 = ofRandom(100);
                ofVec2f vec(i+ran1,k+ran2);
                allVectors.push_back(vec); //TODO: den vector in der ofApp kreiieren und als referenz passen? damt der von allen flash geteilt wird
            }
        }

}

//grid, rect based, vielleicht doppelt so fein wie spielgrid?
//sortiere array nach origin point vom player
    

//alle 0.15 sek:
    //fuer jeden einzelnen blitzanim, mache eine kopie des arrays
        //waehle einen der ersten 6 punkte aus und mache diesen zum origin point
        //sortiere das array abhaneging vom origin point

        //verbinden den ersten und Xten punkt mit einer linie
            //spaeter: X kann immer groesser oder imm kleiner werden
        //speichere den zweiten punkt als origin point (wahrscheinlich brauche ich wenn ich keine klasse mache hier vec opflash1, opflash2...
        //loesche die beiden punkte aus dem urpsruenglichen array, indem ich die koordinaten vergleiche mit dem urpsruenglcihen array und sie rausnehme
//wiederholt sich

//zeichne alle punkte des arrays


//wahrscheinlich brauche eine spawn, eine update und eine draw function
void vfx::spawn(){
    
    //draw grid
    ofSetColor(50, 50, 50);
    for (int i = 0; i < allVectors.size(); i++) {
        ofDrawRectangle(allVectors[i].x, allVectors[i].y, 3,3);
    }
    
    //allVectors
    if(!finished) {
        if(allVectors.size()>0)
        {
            //GET THE FIRST TWO POINTS CLOSE TO PLAYER POS
            //player position
            ofVec2f playerPos(200,500); //TODO: replace with player coordinates
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
                stepper -= 5;
                if(stepper <= 0) {
                    finished = true;
                }
                
            }
            //originPoints.push_back(closestVec); //save for deletion for later
            allVectors.erase(allVectors.begin()); //remove point from array
            
            //sort array again, starting from that new point
            std::sort(allVectors.begin(), allVectors.end(), [&startVec](const ofVec2f& a, const ofVec2f& b) {
                return a.distance(startVec) < b.distance(startVec);
            });
            //now we get the closest point to the point that was closest to the player.
            //if we have been here before then this point will be the closest point to the last end point
            ofVec2f endVec(allVectors[stepper].x, allVectors[stepper].y);
            //originPoints.push_back(nextClosestVec); //save for deletion for later
            //allVectors.erase(allVectors.begin()); //remove point from array as well
            lastEndVec = endVec;
            executedOnce = true;
            
            //verbinden den ersten und Xten punkt mit einer linie
            ofSetColor(250, 50, 50);
            ofSetLineWidth(8);
            ofDrawLine(endVec.x, endVec.y, startVec.x, startVec.y);
            //ofDrawLine(100, 100, closestVec.x, closestVec.y);
            
        }
    }
        
}
