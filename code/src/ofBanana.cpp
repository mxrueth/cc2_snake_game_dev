#include "ofBanana.h"


ofBanana::ofBanana()
{
	ofFood({255,250,0 }, 50);
	pickLocation();
}


void ofBanana::shape() {
	ofDrawRectRounded(pos, scl, scl/1.5, 15);
}