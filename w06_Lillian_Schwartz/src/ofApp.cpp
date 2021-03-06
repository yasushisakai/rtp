#include "ofApp.h"

#define SIZE 500
#define BLACK ofColor(0)

//--------------------------------------------------------------
void ofApp::setup(){

    ping = make_shared<ofImage>();
    pong = make_shared<ofImage>();

    ping->allocate(SIZE,SIZE,OF_IMAGE_GRAYSCALE);
    pong->allocate(SIZE,SIZE,OF_IMAGE_GRAYSCALE);

    int i = 0;
    while (i < ping->getPixels().size()) {
        ping->setColor(i,ofColor(255));
        i++;
    }

    for (int i=0;i<SIZE;i++){
        int x = int(ofRandom(0,SIZE));
        ping->setColor(x,i,BLACK);
    }

    ping->update();
}

void ofApp::subtract(){
 
     int i = 0;
     while (i < ping->getPixels().size()) {
         ofColor s = ping->getColor(i);
         ofColor d = pong->getColor(i);
         if(s.getBrightness()==0 && d.getBrightness() == 0 ){
             pong->setColor(i,255);
         }
         i++;
     }
     pong->update();
 }
 
 
void ofApp::dilute(){

    for(int x=0;x<SIZE;x++){
        for(int y=0;y<SIZE;y++){

            // x x x
            // x o x
            // x x x

            int xm = ofClamp(x-1, 0, SIZE-1);
            int xp = ofClamp(x+1, 0, SIZE-1);
            int ym = ofClamp(y-1, 0, SIZE-1);
            int yp = ofClamp(y+1, 0, SIZE-1);

            ofColor xmym = ping->getColor(xm, ym);
            ofColor x_ym = ping->getColor(x, ym);
            ofColor xpym = ping->getColor(xp, ym);

            ofColor xmy_ = ping->getColor(xm, y);
            ofColor xpy_ = ping->getColor(xp, y);

            ofColor xmyp = ping->getColor(xm, yp);
            ofColor x_yp = ping->getColor(x, yp);
            ofColor xpyp = ping->getColor(xp, yp);

            if (
                xmym.getBrightness() == 0 ||
                x_ym.getBrightness() == 0 ||
                xpym.getBrightness() == 0 ||
                xmy_.getBrightness() == 0 ||
                xpy_.getBrightness() == 0 ||
                xmyp.getBrightness() == 0 ||
                x_yp.getBrightness() == 0 ||
                xpyp.getBrightness() == 0 
            ) {
                pong->setColor(x,y,0);
            } else {
                pong->setColor(x,y,255);
            }
        }
    }

    pong->update();

}
 

//--------------------------------------------------------------
void ofApp::update(){
    dilute();    
    subtract();
    std::swap(ping,pong);
    dilute();    
    std::swap(ping,pong);
    // subtract(pong,ping);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ping->draw(0,0);
    pong->draw(SIZE,0);
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
