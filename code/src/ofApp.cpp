#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // TODO: Play with the frame rate to find a good handling.
    // Yet, think about this approach? What are the pros and cons
    // of using the frame rate and what other approach could be
    // used instead?
	ofSetFrameRate(10);
    
	ofBackground(0);
    gridGeneratePoints();
    flashSetup(7);
	gameOver = false;
	score = 0;
}



void ofApp::gridGeneratePoints()
{
        for (int i = 0; i < ofGetWidth(); i= i+50) {
            for (int k = 0; k < ofGetHeight(); k= k+50) {
                float ran1 = ofRandom(100);
                float ran2 = ofRandom(100);
                ofVec2f vec(i+ran1,k+ran2);
                //ofVec2f vec(i,k);
                allVectors.push_back(vec); //TODO: den vector in der ofApp kreiieren und als referenz passen? damt der von allen flash geteilt wird
            }
        }
}

void ofApp::gridDraw(){
    //draw grid
    ofSetColor(100, 250, 100);
    for (int i = 0; i < allVectors.size(); i++) {
        ofDrawRectangle(allVectors[i].x, allVectors[i].y, 3,3);
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
		}
		if (snake.checkCollision()) {
			gameOver = true;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    gridDraw();
    //flashSetup(4);
//    if(flashes.size() >0) {
//        for(auto& flash : flashes) {
//            cout << "creating " << "\n";
//            flash.create(allVectors);
//            //flash.draw();
//            if(flash.finished) {
//                flash.erase
//            }
//        }
//    }
    if(!flashes.empty()) {
        for(auto& flash : flashes) {
            flash.create(allVectors);
        }
        // Remove all finished flashes
        // Go through all flashes and check if boolean is set to true
        auto newEnd = std::remove_if(flashes.begin(), flashes.end(), [](const vfx& flash) {
            return flash.finished;
        });
        flashes.erase(newEnd, flashes.end());
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
void ofApp::flashSetup(int numberOfFlashes){
     for(int i = 0; i < numberOfFlashes; ++i) {
         cout << "setup" << "\n";
         flashes.push_back(vfx());
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
    case OF_KEY_RETURN: // down
        flashSetup(5);
        break;
	}
}


void ofApp::mouseDragged(int x, int y, int button){


}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
   // flash.generatePoints(x, y);
}



