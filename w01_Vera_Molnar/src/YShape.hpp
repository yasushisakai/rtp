//
//  YShape.hpp
//  w01_Vera_Molnar
//
//  Created by Yasushi Sakai on 2020/09/05.
//

#ifndef YShape_hpp
#define YShape_hpp

#include <stdio.h>
#include "ofApp.h"

class YShape {
public:
    static float size;
    static float thickness;
    
    int id,rot;
    int posx,posy;
    
    void setup(int _id,int _rot);
    void draw();
    
    vector<ofVec3f> pts;
    
};

#endif /* YShape_hpp */
