#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    shader.load("shader");
    plane.set(ofGetWidth(),ofGetHeight(),24,41,OF_PRIMITIVE_TRIANGLES);
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
    shader.setUniform2f("mouseCoord",float(mouseX), float(mouseY));
    // ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofTranslate(ofGetWidth()/2.0,ofGetHeight()/2.0);
    plane.draw();
    shader.end();
}
