#include "ofBanana.h"


ofBanana::ofBanana()
{
	scl = 50;
	color = { 255,255,0 };

	pickLocation();
}


void ofBanana::shape() {
	ofDrawRectRounded(pos, scl, scl/1.5, 15);
}