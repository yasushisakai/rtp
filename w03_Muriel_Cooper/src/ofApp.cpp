#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableDepthTest();
    ofBackground(29,77,138); 
    cam.setFov(2.0*PI/32);
    cam.begin();
    ofSetColor(255,55,38);
    // ofDrawRectangle(-10,10,10,10);
    for(int i=0;i<6;i++){
        drawSquare(240-i*30, 3+i*4, i*40);
    }
    drawSquare(62,62,240);

    ofSetColor(220);
    ofPushMatrix();
    ofRotateZ(45.0);
    drawArrow(250);
    ofRotateZ(90.0);
    drawArrow(250);
    ofPopMatrix();
    cam.end();
}

void ofApp::drawArrow(float z){

    float th = 4;
    float width = 135.0;
    float hw = width / 2.0;
    float head_width = 20;

    ofBeginShape();
    ofVertex(-hw,th*0.5,z);
    ofVertex(hw-head_width,th*0.5,z);
    ofVertex(hw-head_width,th*1.5,z);
    ofVertex(hw,0,z);
    ofVertex(hw-head_width,-th*1.5,z);
    ofVertex(hw-head_width,-th*0.5,z);
    ofVertex(-hw,-th*0.5,z);
    ofEndShape();
}

void ofApp::drawSquare(float size, float width, float z){

    float smallSquareSize = size-width;
    ofBeginShape();
    ofVertex(-size,size,z);    
    ofVertex(size,size,z);    
    ofVertex(size,-size,z);    
    ofVertex(-size,-size,z);    
    ofNextContour(true);
    ofVertex(-smallSquareSize,smallSquareSize,z);    
    ofVertex(smallSquareSize,smallSquareSize,z);    
    ofVertex(+smallSquareSize,-smallSquareSize,z);    
    ofVertex(-smallSquareSize,-smallSquareSize,z);    
    ofEndShape(true); 
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
