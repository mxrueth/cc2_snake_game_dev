#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // TODO: Play with the frame rate to find a good handling.
    // Yet, think about this approach? What are the pros and cons
    // of using the frame rate and what other approach could be
    // used instead?
	//ofSetFrameRate(30);
    
	ofBackground(0);
	gameOver = false;
	score = 0;
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
	}
}






