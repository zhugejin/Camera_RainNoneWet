#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxGui.h"
#include "ofxOpenCv.h"
#include "ofxKinect.h"
#include "Drop.hpp"



class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    
    
    ofVideoGrabber cam;
    ofxCv::ContourFinder contourFinder;
    ofMesh mesh;
    ofMesh normalLines;
    
    ofColor targetColor;
    ofEasyCam Ecam;
    
    ofxPanel gui;
    ofParameter<float> minArea, maxArea, threshold;
    ofParameter<bool> holes;
    ofParameter<bool> trackHs;
    
    ofxCvGrayscaleImage grayImage;
    
    ofVideoPlayer movie;
    bool showLabels;
    bool blobDetected;
    
    float nearThresh, farThresh;
    float grayFarThresh, grayNearThresh;
    float normalLength;
    
    
    int angle = 20;
    int skip = 2;
    
    ofSoundPlayer water;
    
    int bands;
    float * fftSmooth;
    
    vector<Drop> drops;
};
