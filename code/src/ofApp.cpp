#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // TODO: Play with the frame rate to find a good handling.
    // Yet, think about this approach? What are the pros and cons
    // of using the frame rate and what other approach could be
    // used instead?
	ofSetFrameRate(10);
    
	ofBackground(0);

	// Setze die Position, Größe und Farbe der Schlange
	//snake.myPos = ofPoint(100, 100);
	//snake.cellSize = 20;
	//snake.colorIO = ofColor::green;
}

//--------------------------------------------------------------
void ofApp::update(){
	
	
	mySnake.updateSnake();

	if (mySnake.eat(myFood.myPos)) {
		myFood.pickLocation();
        
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
    
	mySnake.drawSnake();
	myFood.drawFood();
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
	mySnake.keyPressed(key); // Weiterleiten der Tastendrücke an die Schlange
}






