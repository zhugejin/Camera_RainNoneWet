//
//  Glow.hpp
//  myFocusedSketch
//
//  Created by Gejin Zhu on 10/25/19.
//

#ifndef Glow_hpp
#define Glow_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxCv.h"

class Glow : public ofxCv::RectFollower {
protected:
    ofColor color;
    ofVec3f cur, smooth;
    float startedDying;
    ofPolyline all;
public:
    Glow()
    :startedDying(0) {
    }
    void setup(const cv::Rect& track);
    void update(const cv::Rect& track);
    void kill();
    void draw();
};

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    
    ofVideoPlayer movie;
    ofxCv::ContourFinder contourFinder;
    ofxCv::RectTrackerFollower<Glow> tracker;
};

#endif /* Glow_hpp */
