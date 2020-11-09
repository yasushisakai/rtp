#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    car.load("car.mov");
    car.play();
    car.setVolume(0);
    car.setSpeed(0.25);
    frame.allocate(car.getWidth(),car.getHeight(),OF_IMAGE_COLOR);

    grabber.listDevices();
    grabber.setDeviceID(0);
    grabber.setup(640, 480);

    prevGrab.allocate(grabber.getWidth(),grabber.getHeight(),OF_IMAGE_GRAYSCALE);
    deltas.allocate(grabber.getWidth(),grabber.getHeight(),OF_IMAGE_COLOR);
}

//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();
    car.update();
    if (grabber.isFrameNew()) {
        ofPixels grab = grabber.getPixelsRef();
        for(int i=0;i<grab.size();i++){
            ofColor g = grab.getColor(i);
            ofColor p = prevGrab.getColor(i);
            if(abs(g.getBrightness()-p.getBrightness())<20) {
                deltas.setColor(i, 255);
            } else {
                deltas.setColor(i, 0);
            }
        }
        deltas.update();
        prevGrab.setFromPixels(grabber.getPixelsRef());
    }
    ofPixels carPix = car.getPixelsRef();
    for(int x=0;x<frame.getWidth();x++) {
        for (int y=0;y<frame.getHeight();y++) {
            int tx = int(ofMap(x,0,frame.getWidth(),0,deltas.getWidth()));
            int ty = int(ofMap(y,0,frame.getHeight(),0,deltas.getHeight()));
            bool isBlack = deltas.getColor(tx,ty) == ofColor(0);
            if (isBlack) {
                ofColor carColor = carPix.getColor(x,y);
                frame.setColor(x,y, carColor);
            }
        }
    }
    frame.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    frame.draw(0,0);
    // deltas.draw(0,0);
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
