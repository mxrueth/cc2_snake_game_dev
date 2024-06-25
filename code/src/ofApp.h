#pragma once

#include "ofMain.h"
#include "ofSnake.h"
#include "ofFood.h"
#include "vfx.h"



// TODO: Refactoring
// This class works but does not follow the best
// code design approach if you think of separating
// interface from implementation and access levels.
// Review all classes and improve the respective
// implementations accordingly.


class ofApp : public ofBaseApp{

	public:
	
		void setup();
		void update();
        void draw();

		void keyPressed(int key);
        void increaseSpeed();
    
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
    
        vector<ofVec2f> allVectors;
        std::vector<vfx> flashes;
		

	private:
        //vfx
        void gridGeneratePoints();
        void gridDraw();
        void vfxDraw(ofPoint headPos);
        void flashSetup(int numOfFlashes);
    
		ofSnake snake;
		ofFood food;
		bool gameOver;
		int score;
    
    
}
;
