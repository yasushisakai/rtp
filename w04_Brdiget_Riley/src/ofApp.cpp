#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    shader.load("shader");
}

//--------------------------------------------------------------
void ofApp::update(){
    if(ofGetElapsedTimef() > 5.0f){
        shader.load("shader");
        ofResetElapsedTimeCounter();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    shader.begin();
    shader.setUniform2f("windowSize",float(ofGetWidth()),float(ofGetHeight()));
    shader.setUniform2i("division", 27, 41);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    shader.end();
}
