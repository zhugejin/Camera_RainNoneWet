//
//  Drop.cpp
//  raintest
//
//  Created by Gejin Zhu on 10/24/19.
//

#include "Drop.hpp"
#include "ofMain.h"

void Drop::reset(){
    x = ofRandomWidth();
    y = ofRandom(-500, -50);
    z = ofRandom(0, 20);
    length = ofMap(z, 0, 20, 10, 20);
    yspeed = ofMap(z, 0, 20, 1, 20);
    thick = ofMap(z, 0, 20, 1, 3);
    gravity = ofMap(z, 0, 20, 0, 0.2);

}

void Drop::update(){
    y = y + yspeed;
    yspeed = yspeed + gravity;
    if (y > ofGetHeight()){
        y = ofRandom(-200, -100);
        yspeed = ofMap(z, 0, 20, 4, 10);

        
        
    }
}

void Drop::draw(){
    ofDrawLine(x, y, x, y+length);
    ofSetLineWidth(thick);

    
}
