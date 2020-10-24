#include "ofApp.h"
#include <glm/gtx/intersect.hpp>
using namespace glm;

#define EDGE_NUM 12
#define RADIUS 465.0

//--------------------------------------------------------------
void ofApp::setup(){

    vec3 origin = vec3(0.0,0.0,0.0);
    vec3 top = vec3(0.0,RADIUS,0.0);

    vector<vec3> outerPolygon;
    float unitAngle = 2.0*PI/float(EDGE_NUM);
    for(int i =0;i<EDGE_NUM;i++){
        float x = sin(unitAngle*i)*RADIUS;
        float y = cos(unitAngle*i)*RADIUS;
        outerPolygon.push_back(vec3(x,y,0.0));
    } 

    vector<vec3> innerPolygon;
    for(int i =0;i<EDGE_NUM;i++){
        float x = sin(unitAngle*i)*RADIUS*0.5;
        float y = cos(unitAngle*i)*RADIUS*0.5;
        innerPolygon.push_back(vec3(x,y,0.0));
    }

    for(int i=0;i<EDGE_NUM;i++) {
        innerShape.push_back(innerPolygon.at(i));
        vec3 mp = (innerPolygon.at(i) + innerPolygon.at((i+1)%EDGE_NUM))*0.5;
        innerShape.push_back(mp);
    }

    // top center shape C
    vec3 innerTop = innerPolygon.at(0);
    float diamondEdgeLength = distance(innerPolygon.at(0),innerPolygon.at(1));
    vec3 tempPoint = vec3(innerTop.x,innerTop.y+diamondEdgeLength*sqrt(2),0.0);
    vec3 rectCenter = (tempPoint + innerTop) *0.5;
    vec3 diamondLeft, diamondRight;
    diamondRight = rectCenter - vec3(diamondEdgeLength/sqrt(2), 0.0, 0.0);
    diamondLeft = rectCenter + vec3(diamondEdgeLength/sqrt(2), 0.0, 0.0);

    vector<vec3> tcsc;
    tcsc.push_back(tempPoint);    
    tcsc.push_back(diamondRight);    
    tcsc.push_back(innerTop);    
    tcsc.push_back(diamondLeft);    
    diamonds.push_back(tcsc);

    // top squashed rectangle shape A
    vec3 outer1 = outerPolygon.at(1);
    vec3 outerEdgeMidPoint = (top + outer1)*0.5;
    vec3 outerEdgeMidPointLast = (top + outerPolygon.at(EDGE_NUM-1))*0.5;
    vector<vec3> tsr;
    tsr.push_back(top);
    tsr.push_back(outerEdgeMidPoint);
    tsr.push_back(tempPoint);
    tsr.push_back(outerEdgeMidPointLast);
    diamonds.push_back(tsr);

    // first right shape B 
    vec3 outerEdgeMidPoint2 = (outer1 + outerPolygon.at(2))*0.5;
    vec3 intersection1;
    ofLineSegmentIntersection(outerEdgeMidPoint2, outerEdgeMidPointLast, outer1, origin, intersection1);
    vector<vec3> frsb;
    frsb.push_back(outerEdgeMidPoint);
    frsb.push_back(tempPoint);
    frsb.push_back(diamondLeft);
    frsb.push_back(intersection1);
    diamonds.push_back(frsb);
    diamonds.push_back(horizontalFlip(frsb));

    // second right shape A-1
    vector<vec3> srsa1;
    srsa1.push_back(outerEdgeMidPoint);
    srsa1.push_back(intersection1);
    srsa1.push_back(outerEdgeMidPoint2);
    srsa1.push_back(outerPolygon.at(1));
    diamonds.push_back(srsa1);
    diamonds.push_back(horizontalFlip(srsa1));

    // second right shape B
    vector<vec3> srsb;
    vec3 inner2 = innerPolygon.at(2);
    vec3 intersection2; 
    ofLineSegmentIntersection(intersection1, inner2, outerEdgeMidPoint2, innerTop, intersection2);
    srsb = {innerTop, innerPolygon.at(1), intersection2, diamondLeft};
    diamonds.push_back(srsb);
    diamonds.push_back(horizontalFlip(srsb));

    // second right shape A 2
    vector<vec3> srsa2 = {diamondLeft, intersection2, outerEdgeMidPoint2, intersection1};
    diamonds.push_back(srsa2);
    diamonds.push_back(horizontalFlip(srsa2));

    vec3 outer2shift_h = outerPolygon.at(2) - vec3 (diamondEdgeLength*sqrt(2), 0, 0);
    vector<vec3> remainA = {intersection2, innerPolygon.at(1), outer2shift_h, outerEdgeMidPoint2};
    diamonds.push_back(horizontalFlip(remainA));

    vec3 outer2shift_v = outerEdgeMidPoint2 - vec3(0,diamondEdgeLength*sqrt(2), 0);
    vector<vec3> remainB = {outerPolygon.at(2), outer2shift_v, outer2shift_h, outerEdgeMidPoint2};
    diamonds.push_back(horizontalFlip(remainB));

    vector<vec3> remainC = {outer2shift_v, outer2shift_h, innerPolygon.at(1), innerPolygon.at(2)};
    diamonds.push_back(horizontalFlip(remainC));

    vec3 outerEdgeMidPoint3 = (outerPolygon.at(2) + outerPolygon.at(3)) * 0.5;
    vec3 lastPoint = outerEdgeMidPoint3 - (outerPolygon.at(2) - outer2shift_v);
    vector<vec3> remainB2 = {outerPolygon.at(2), outerEdgeMidPoint3, lastPoint, outer2shift_v};
    diamonds.push_back(horizontalFlip(remainB2));
    vector<vec3> remainC2 = {lastPoint, innerPolygon.at(3), innerPolygon.at(2), outer2shift_v};
    diamonds.push_back(horizontalFlip(remainC2));
}

//--------------------------------------------------------------
void ofApp::update(){


}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(1,22,78);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(255,255,255);
    ofPushMatrix();
    ofTranslate(ofGetWidth()*0.5, ofGetHeight()*0.5);
    ofRotateZ(180);

    for(int i=0;i<innerShape.size();i++) {
        ofDrawLine(vec3(0.0,0.0,0.0), innerShape.at(i));
    }

    for(int j=0;j<3;j++){
        ofPushMatrix();
        ofRotateZ(j*120);
        for(int i =0;i<diamonds.size();i++) {
            drawDiamond(diamonds.at(i));
        }
        ofPopMatrix();
    }

    ofPopMatrix();
}

void ofApp::drawDiamond(vector<vec3> points){
    ofSetColor(255);
    ofBeginShape();
        ofVertices(points);
    ofEndShape(true);

    ofDrawLine(points.at(0),points.at(2));
    ofDrawLine(points.at(1),points.at(3));

    vector<vec3> diamond;
    for (int i=0;i<points.size()-1;i++){
        vec3 a = points.at(i);
        vec3 b = points.at(i+1);
        vec3 mid = (a+b)*0.5;
        diamond.push_back(mid); 
    }

    vec3 a = points.at(points.size()-1);
    vec3 b = points.at(0);
    vec3 mid = (a+b)*0.5;
    diamond.push_back(mid); 

    ofDrawLine(diamond.at(0),diamond.at(2));
    ofDrawLine(diamond.at(1),diamond.at(3));

    ofSetColor(255,200);
    ofFill();
    ofBeginShape();
        ofVertices(diamond);
    ofEndShape(close);
    ofNoFill();
}

vector<vec3> ofApp::horizontalFlip(vector<vec3> points) {
    vec3 reflect = vec3(-1.0, 1.0, 1.0);
    vector<vec3> new_points;
    for (int i=0;i<points.size();i++) {
        new_points.push_back(points.at(i) * reflect);
    }
    return new_points;
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
