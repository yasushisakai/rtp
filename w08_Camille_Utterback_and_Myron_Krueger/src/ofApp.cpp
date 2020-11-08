#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // grabber.listDevices();
    // grabber.setup(640,480);

    video.load("car.mov");
    // video.play(); // key pressed
}

//--------------------------------------------------------------
void ofApp::update(){
    video.update();
    grabber.update();
    //if(grabber.isFrameNew()) {


    //}
}

//--------------------------------------------------------------
void ofApp::draw(){
    // grabber.draw(0,0);
    video.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (!video.isPlaying()) {
        video.play();
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
