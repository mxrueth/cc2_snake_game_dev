#pragma once

#include "ofMain.h"
#include "ofSnake.h"
#include "ofFood.h"
#include "ofApple.h"
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

        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
    
        vector<ofVec2f> allVectors;
        std::vector<vfx> flashes;
		
        void spawnFood(float speed);

	private:
        //vfx
        void gridGeneratePoints();
        void gridDraw();
        void vfxDraw(ofPoint headPos);
        void flashSetup(int numOfFlashes);
    
		ofSnake snake;
		

        vector<ofFood*> foods;

        bool gameOver;
		bool collectedFood;
		int score;

        float lastUpdateTime = 0.0;
    
    
}
;
