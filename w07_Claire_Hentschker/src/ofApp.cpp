#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    video.setUseTexture(false);
    video.load("fallguys_trimed.mov");
    cout << "total frame numbers: " << video.getTotalNumFrames() << endl;
    video.play();

    vHeight = 720;
    vWidth = 1280;
    // expWeight = 1.0/256.0;
    expWeight = 0.01;

    pixels.allocate(vWidth, vHeight, OF_IMAGE_COLOR);
    img.allocate(vWidth,vHeight, OF_IMAGE_COLOR);

    for(int i=0;i<pixels.size();i++){
        img.setColor(i, ofColor(255,255,255));
    } 

    img.update();
}

//--------------------------------------------------------------
void ofApp::update(){
    video.update();

    if(video.isFrameNew()) {
        ofPixels vPix = video.getPixels();
        for (int i=0;i < vPix.size();i++) {
            ofFloatColor imgPixColor = img.getColor(i);
            ofFloatColor newPixColor = vPix.getColor(i);

            ofFloatColor mix;
            // this uses the expotentially weighted average that is sometimes used in Deep Learning
            mix.r = (imgPixColor.r)*(1.0-expWeight) + (newPixColor.r)*expWeight;
            mix.g = (imgPixColor.g)*(1.0-expWeight) + (newPixColor.g)*expWeight;
            mix.b = (imgPixColor.b)*(1.0-expWeight) + (newPixColor.b)*0.01;

            img.setColor(i, mix);
        } 
        img.update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    img.draw(0,-90);
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
