#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // TODO: Play with the frame rate to find a good handling.
    // Yet, think about this approach? What are the pros and cons
    // of using the frame rate and what other approach could be
    // used instead?
	ofSetFrameRate(15);
	ofBackground(0);
    
	gameOver = false;
	score = 0;    
    //VFX
    gridGeneratePoints();
}
//--------------------------------------------------------------

//VFX, create the grid
void ofApp::gridGeneratePoints()
{
    for (int i = 0; i < ofGetWidth(); i= i+50) {
        for (int k = 0; k < ofGetHeight(); k= k+50) {
            float ran1 = ofRandom(100);
            float ran2 = ofRandom(100);
            ofVec2f vec(i+ran1,k+ran2);
            //ofVec2f vec(i,k);
            allVectors.push_back(vec);
        }
    }
}
//VFX
void ofApp::flashSetup(int numberOfFlashes){
     for(int i = 0; i < numberOfFlashes; ++i) {
         flashes.push_back(vfx());
     }
}
//VFX
void ofApp::gridDraw(){
    //draw grid
    ofSetColor(100, 250, 100);
    for (int i = 0; i < allVectors.size(); i++) {
        ofDrawRectangle(allVectors[i].x, allVectors[i].y, 3,3);
    }
}
//VFX, pass the grid and snake position to be used for the flash animation
void ofApp::vfxDraw(ofPoint position) {
    if(flashes.size() <= 0) {
        flashSetup(9);
    }else{
        for(auto& flash : flashes) {
            flash.animate(allVectors, position);
            if(flash.finished) {
                collectedFood = false;
            }
        }
        // Remove all finished flashes
        // Go through all flashes and check if the "finished" boolean is set to true
        auto newEnd = std::remove_if(flashes.begin(), flashes.end(), [](const vfx& flash) {
            return flash.finished;
        });
        flashes.erase(newEnd, flashes.end());
        
    }
}


//--------------------------------------------------------------
void ofApp::update(){
	if (!gameOver) {
		snake.update();
		if (snake.body.front()==food.pos) {
			score += 50;
			snake.grow();
			food.pickLocation();
            collectedFood = true; //run VFX
		}
		if (snake.checkCollision()) {
			gameOver = true;
		}
	}
}


//--------------------------------------------------------------
void ofApp::draw(){
    
    gridDraw();
    if(collectedFood)
    {
        vfxDraw(snake.getPosHead());
    }
    
	if (gameOver) {
		ofDrawBitmapString("Game Over", ofGetWidth() / 2 - 50, ofGetHeight() / 2);
	}
	else {
		snake.draw();
		food.draw();
		ofDrawBitmapString("Score:"+ofToString(score), 50, ofGetHeight() - 25);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
	switch (key) {

	case OF_KEY_LEFT: // left
		snake.setDir(-1, 0);
		break;
	case OF_KEY_RIGHT: // right
		snake.setDir(1, 0);
		break;
	case OF_KEY_UP: // up
		snake.setDir(0, -1);
		break;
	case OF_KEY_DOWN: // down
		snake.setDir(0, 1);
		break;
    case OF_KEY_RETURN: // Cheat to trigger vfx
        vfxDraw(snake.getPosHead());
        collectedFood = true;
        break;
	}
}


void ofApp::mouseDragged(int x, int y, int button){


}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
   // flash.generatePoints(x, y);
}



