/*
 *  ofxImageMask.h
 *  emptyExample
 *
 *  Created by Oriol Ferrer Mesià on 28/01/11.
 *  Copyright 2011 uri.cat. All rights reserved.
 *
 */

#pragma once

#include "ofMain.h"

class ofxImageMask: public ofImage {

public:
	
	ofxImageMask():ofImage(){};

	void applyMask(string maskImagePath, bool invert = false);	
	void applyMask(ofImage & mask, bool invert = false);

	//implementing copy ctr and operator to be able to mix with ofImage
	ofxImageMask(const ofImage_& d): ofImage_(d) {}
	
    ofxImageMask& operator= (const ofxImageMask& d){
        ofImage_::operator=(d);
        return *this;
    }
};

