#include "ofApple.h"


ofApple::ofApple()
{

	//ofFood(glm::vec3(0,250,50), 50);
	//scl = 50;
	
	ofFood({ 0,250,50 }, 50);

	pickLocation();
}


void ofApple::shape() {
	ofDrawRectRounded(pos, scl, scl,10);
}