#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	seed = 0;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofBackground(242, 239, 234);
	
	ofSetColor(109,136,181);

	ofSetLineWidth(1.75);
	ofNoFill();

	ofSeedRandom(seed);
	
	for (int i = 0; i < 29; i++) {
		float y = ofMap(i, 0, 28, 80, 820);
		line.clear();
		for (int j = 0; j < 75; j++) {
			float x = ofMap(j, 0, 74, 160, 1040);
			float multiplier = ofMap(j, 0, 74, 0, 1);
			float range = ofMap(mouseY, 0, 800, 0, 10);
			noise = ofMap(ofNoise(i*.2, j*.05, mouseX*.005), 0, 1, -range, range);
			rand = ofRandom(-range, range);
			float combined = (noise + rand)*multiplier;

			line.addVertex(ofVec3f(x - 9.0 + combined, y + 9.0 + combined, 0));
			line.addVertex(ofVec3f(x + 20.0 + combined, y - 9.0 + combined, 0));

		}
	
		line.draw();
	}
	//ofSleepMillis(30000);
	//ofDrawBitmapString("fps: " + ofToString(ofGetFrameRate()), 10, 10);
	//ofDrawBitmapString("noise: " + ofToString(noise), 10, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 's') {
		img.grabScreen(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
		string fileName = "01_VM_letter_" + ofGetTimestampString("%y-%m-%d-%H%M") + ".png";
		img.save(fileName);
	}
	if (key == 'x') {
		seed = mouseY;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
