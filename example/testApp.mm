#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){	
	
	ofEnableAlphaBlending();	
	ofBackground(127,127,127);
	
	original.loadImage("original.png");
	mask.loadImage("mask.png");
	destination = original;
	destinationInvert = original;
	
	destination.applyMask(mask);
	destinationInvert.applyMask(mask, true); //true for invert
}


//--------------------------------------------------------------
void testApp::draw(){

	original.draw(0, 0);
	mask.draw(original.getWidth(), 0);
	destination.draw(0, original.getHeight() );
	destinationInvert.draw(0, 2 * original.getHeight() );
	
}

