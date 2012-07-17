#pragma once

#include "ofMain.h"
#include "ofxiPhone.h"
#include "ofxiPhoneExtras.h"

#include "ofxImageMask.h"

class testApp : public ofxiPhoneApp{
	
public:
	void setup();
	void draw();
	
	void touchDown(ofTouchEventArgs & touch){};
	void touchMoved(ofTouchEventArgs & touch){};
	void touchUp(ofTouchEventArgs & touch){};
	void touchDoubleTap(ofTouchEventArgs & touch){};
	void touchCancelled(ofTouchEventArgs & touch){};
	
	ofImage original;
	ofImage mask;
	ofxImageMask destination;
	ofxImageMask destinationInvert;
	
	
};


