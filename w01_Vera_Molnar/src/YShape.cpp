//
//  YShape.cpp
//  w01_Vera_Molnar
//
//  Created by Yasushi Sakai on 2020/09/05.
//

#include "YShape.hpp"

float YShape::size{200};
float YShape::thickness{50};


void YShape::setup(int _id,int _rot){
    id = _id;
    rot = _rot;
    
    bool right = false;
    bool left = false;
    
    if (id/5<4 && id%5>0 ) {
        if (rot == 2) {
            right = true;
        }
    
        if (rot ==3 ) {
            left = true;
        }
    }
    
    posx = id%5;
    posy = id/5;
    
    float cx1 = YShape::thickness / sqrt(2);
    float cx2 = (YShape::size - YShape::thickness) / 2.0;
    float cx3 = YShape::size/2.0;
    float cx4 = (YShape::size + YShape::thickness) / 2.0;
    float cx5 = YShape::size - cx1;
    
    float cy1 = cx1;
    float cy2 = cx3 - cx1;
    float cy3 = cx1 + cx2;
    
    pts.push_back(ofVec3f(cx3,cy2));
    pts.push_back(ofVec3f(cx5,0));
    pts.push_back(ofVec3f(YShape::size,cy1));
    pts.push_back(ofVec3f(cx4,cy3));
    pts.push_back(ofVec3f(cx4,YShape::size));
    pts.push_back(ofVec3f(cx2,YShape::size));
    pts.push_back(ofVec3f(cx2,cy3));
    pts.push_back(ofVec3f(0,cy1));
    pts.push_back(ofVec3f(cx1,0));
    
    if (right) {
        pts[1] += ofVec3f(cx1,-cy1);
        pts[2] += ofVec3f(cx1,-cy1);
    }

    if (left) {
        pts[7] += ofVec3f(-cx1, -cy1);
        pts[8] += ofVec3f(-cx1, -cy1);
    }
    
    for (int i=0;i<pts.size();i++){
        pts[i] -= ofVec3f(YShape::size/2.0,YShape::size/2.0,0);
    }
    
}

void YShape::draw(){
    ofPushMatrix();
    ofTranslate((posx+0.5)*YShape::size, (posy+0.5)*YShape::size);
    ofRotateDeg(90*rot);
    ofBeginShape();
    ofVertices(pts);
    ofEndShape();
    ofPopMatrix();
}
