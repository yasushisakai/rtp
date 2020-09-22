#include "ofApp.h"

#define NUMHEX 24;

//--------------------------------------------------------------
void ofApp::setup(){
    // ofSetFrameRate(10);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableAlphaBlending();
    ofSetColor(0,0,0,10);
    ofFill();    
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
    float r = 200.0;
    float sr = 35;
    float hexDeg = (2.0 * PI)/6.0;

    ofSetColor(255);
    ofNoFill();
    for (int i=0; i < 24; i++){
        float flip=1;
        if (i%2==0) {
            flip=-1;
        }
        // float polarId = (i/24.0)*PI;
        float deg = ((ofGetFrameNum()+i)/360.0) * (2.0*PI);
        float x = flip * cos(deg*1.2+sin(i*2.0)*2.0)*r+ofGetWidth()/2.0;
        float y = sin(deg*0.9+cos(i*2.0)*2.0)*r+ofGetHeight()/2.0;
        ofBeginShape();
        // float tempRadius = sr + (10 * (i/2)) * sin(deg);
        float tempRadius = sr + 4 * ((sin(deg)+1.0)*0.8) * (i/2);
        // float tempRadius = 1.0;
        for (int j=0;j < 6;j++){
            ofVertex(x+sin(hexDeg*j)*tempRadius,y+cos(hexDeg*j)*tempRadius);
        }
        ofEndShape(true);
    }

    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
