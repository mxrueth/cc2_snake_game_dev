#include "ofApple.h"


ofApple::ofApple()
{
	scl = 50;
	color = { 0,250,50 };

	pickLocation();
}


void ofApple::shape() {
	ofDrawRectRounded(pos, scl, scl,10);
}