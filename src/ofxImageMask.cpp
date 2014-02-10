/*
 *  ofxImageMask.cpp
 *  emptyExample
 *
 *  Created by Oriol Ferrer Mesià on 28/01/11.
 *  Copyright 2011 uri.cat. All rights reserved.
 *
 */

#include "ofxImageMask.h"
#include <float.h>

void ofxImageMask::applyMask(string maskImagePath, bool invert){

	ofImage mask;
	mask.loadImage(maskImagePath);
	applyMask(mask, invert);
}


void ofxImageMask::applyMask(ofImage & mask, bool invert){
	
	if (getWidth() == mask.getWidth() && getHeight() && mask.getHeight() ){
		
		if (getPixelsRef().getImageType() != OF_IMAGE_COLOR_ALPHA){
			setImageType(OF_IMAGE_COLOR_ALPHA);
		}
		
		if (mask.getPixelsRef().getImageType() != OF_IMAGE_GRAYSCALE){
			mask.setImageType(OF_IMAGE_GRAYSCALE);
		}

		int totalPixels = getWidth() * getHeight();
		unsigned char * maskPix = mask.getPixels();
		unsigned char * targetPix = getPixels();
		
		for(int i = 0; i < totalPixels; i++){
			targetPix[ 4 * i + 3 ] = invert ? 255 - maskPix[i] : maskPix[i];
		}
		update();
	}else{
		ofLog(OF_LOG_ERROR, "ofxImageMask:: can't apply mask, original and mask images are different sizes");
	}
}
