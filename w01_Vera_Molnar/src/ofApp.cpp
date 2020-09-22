#include "ofApp.h"

#define YNUM 25

YShape shapes[YNUM];

//--------------------------------------------------------------
void ofApp::setup(){
    
    int rots[YNUM] = {
        3, 0, 1, 2, 3,
        2, 3, 0, 1, 2,
        1, 2, 3, 0, 1,
        0, 1, 2, 3, 0,
        3, 0, 1, 2, 3
    };
    
    for (int i=0;i<YNUM;i++){
        int rot = ((3 - i/5) + i%5) % 4;
        // int rot = (3+i)%4;
        shapes[i].setup(i,rot);
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    
    ofSetColor(1,118,48);
    ofFill();
    for (int i=0;i<YNUM;i++){
        shapes[i].draw();
    }
    
}
