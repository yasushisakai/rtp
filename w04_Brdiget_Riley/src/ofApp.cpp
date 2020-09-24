#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    shader.load("shader");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    shader.begin();
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    shader.end();
}
