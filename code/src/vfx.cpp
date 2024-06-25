#include "vfx.h"

using namespace std;


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
                ofVec2f vec(i,k);
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
    if(allVectors.size()>0)
    {
        //GET THE FIRST TWO POINTS CLOSE TO PLAYER POS
        //player position
        ofVec2f originVec(200,500); //TODO: replace with player coordinates
        //sortiere das array abhaneging vom origin point, thanks AI
        std::sort(allVectors.begin(), allVectors.end(), [&originVec](const ofVec2f& a, const ofVec2f& b) {
            return a.distance(originVec) < b.distance(originVec);
        });
        //get the first closest point to player
        ofVec2f closestVec(allVectors[0].x, allVectors[0].y);
        originPoints.push_back(closestVec); //save for deletion for later
                
        //sort array again, starting from that new point
        std::sort(allVectors.begin(), allVectors.end(), [&closestVec](const ofVec2f& a, const ofVec2f& b) {
            return a.distance(closestVec) < b.distance(closestVec);
        });
        ofVec2f nextClosestVec(allVectors[1].x, allVectors[1].y);
        originPoints.push_back(nextClosestVec); //save for deletion for later
                    
        //verbinden den ersten und Xten punkt mit einer linie
        ofSetColor(250, 50, 50);
        ofDrawLine(nextClosestVec.x, nextClosestVec.y, closestVec.x, closestVec.y);
        //ofDrawLine(100, 100, closestVec.x, closestVec.y);
  
    }
        
}
