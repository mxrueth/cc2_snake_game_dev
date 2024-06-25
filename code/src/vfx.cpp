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
                allVectors.push_back(vec);
            }
        }

    
    //if(counterPointsGenerated < 50)
    //{
 //   pointsGenerated = true;
    //}
 //       vecAtMouse.set(x, y);
        
    //hmm doesn't help avoiding the first point being in the corner...why?
    //    if(x > 0) {
    //        vecAtMouse.set(x, y);
    //    }else{
    //        vecAtMouse.set(600, 600);
    //    }
}


void vfx::spawn(){
    
    ofSetColor(50, 50, 50);
    for (int i = 0; i < allVectors.size(); i++) {
        ofRectangle(allVectors[i].x, allVectors[i].y, 5,5);
    }
    
    //Design
    //create random points around the mouse and write them to array
    //OR create grid of points in the beginning
    
    //draw all points
    //move circle from origin point to closest other point, each time a point is picked it is taken out of the array so it can't be picked again //next closest point
        //write moving function (use update?)
        //TODO: go through array and sort by distance
        //take the closest one
        //copy this as an end point to my move function
        //remove from array
        //repeat for other points
    
    //with each moving, the circle shrinks
    
    //polish: instead of circle, it's an animation that plays quicker the faster the transition from point to point
        // random points need a minimum distance then
        
    int range = 300;
    if(ofGetMousePressed())
    {
        //TODO: Generate points once every X seconds oly
        
//            for (int i =0; i<pointsPerClick; i++)
//            {
                //counterPointsGenerated += 1;
                //Generate random point around the current mousePos and add it to the array
                float x = ofRandom(-range, range);
                float y = ofRandom(-range, range);
                ofVec2f randomVec(x,y);
                ofVec2f newVec(vecAtMouse + randomVec);
                //line.addVertex(newVec.x, newVec.y);
                allVectors.push_back(newVec);
                ofDrawCircle(newVec.x, newVec.y, 7);
                
    }
    
    
    
    //sort array by distance for the first moving circles. Get the target for the first circle, the second target for the second circle...
    //new idea: first sort, then create an array just with X goal points from that. so the closest ones...
    //OR create a pair vector...we take the origin and one of the X goals...
    //vielleicht am besten eine circle class machen?
        //klasse referenz zum array und vielleicht nur ein weg durchs array
    //
    
    //grid, rect based, vielleicht doppelt so fein wie spielgrid?
    //sortiere array nach origin point vom player
        
    
    //alle 0.15 sek:
    //for 6 times:
        //fuer jeden einzelnen blitzanim, mache eine kopie des arrays
            //waehle einen der ersten 6 punkte aus und mache diesen zum origin point
            //sortiere das array abhaneging vom origin point
            //verbinden den ersten und Xten punkt mit einer linie
                //spaeter: X kann immer groesser oder imm kleiner werden
            //speichere den zweiten punkt als origin point (wahrscheinlich brauche ich wenn ich keine klasse mache hier vec opflash1, opflash2...
            //loesche die beiden punkte aus dem urpsruenglichen array, indem ich die koordinaten vergleiche mit dem urpsruenglcihen array und sie rausnehme
    //wiederholt sich
    
    //zeichne alle punkte des arrays
    
    
    //allVectors
    if(allVectors.size()>0)
    {
        ofVec2f originVec(500,500);
        // Sort the points by distance from X //thanks AI
        std::sort(allVectors.begin(), allVectors.end(), [&originVec](const ofVec2f& a, const ofVec2f& b) {
            return a.distance(originVec) < b.distance(originVec);
        });
        ofVec2f closestVec(allVectors[0].x, allVectors[0].y);
        
        for (int i =0; i<5; i++) {
            originPoints.push_back(closestVec);
            // allVectors.erase(allVectors.begin());
            ofLine(originVec.x, originVec.y, closestVec.x, closestVec.y);
        }
    }
        
    for (ofVec2f existingVec : allVectors)
    {
        int x = existingVec.x;
        int y = existingVec.y;

        ofDrawCircle(x, y, 3);
        
    }    
}
