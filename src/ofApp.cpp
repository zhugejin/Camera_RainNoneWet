#include "ofApp.h"
#include "ofxKinect.h"
#include "Drop.hpp"
#include "ofxCv.h"


using namespace ofxCv;
using namespace cv;

void ofApp::setup() {
    //cam
    cam.setup(1024, 768);
    contourFinder.setMinAreaRadius(100);
    contourFinder.setMaxAreaRadius(200);
    contourFinder.setThreshold(10);
    
    //gui
    gui.setup();
    gui.add(minArea.set("Min area", 10, 1, 100));
    gui.add(maxArea.set("Max area", 200, 1, 500));
    gui.add(threshold.set("Threshold", 128, 0, 255));
    gui.add(holes.set("Holes", false));
    
    //drop
    int numDrop = 500;
    for (int i = 0; i < numDrop; i++)
    {
        Drop newDrop;
        newDrop.reset();
        drops.push_back(newDrop);
        
    }
    
    // load sound
    water.load("Sounds/water.mp3");
    water.setMultiPlay(true);
    water.setLoop(true);
    water.setVolume(0.2);
   
    
    
    
    
    
}



void ofApp::update() {
    ofSetBackgroundColor(0);
    //cam
    cam.update();
    if(cam.isFrameNew()) {
        contourFinder.setTargetColor(targetColor, trackHs ? TRACK_COLOR_HS : TRACK_COLOR_RGB);
       contourFinder.setThreshold(threshold);
       contourFinder.findContours(cam);
   }
    if(cam.isFrameNew()) {
        contourFinder.setMinAreaRadius(minArea);
        contourFinder.setMaxAreaRadius(maxArea);
        contourFinder.setThreshold(threshold);
        contourFinder.findContours(cam);
        contourFinder.setFindHoles(holes);
    }
    //drop
    for (int i = 0; i < 100; i++)
    {
        drops[i].update();
    }
   
    //sound
    ofSoundUpdate();
    
    
    
    float * value = ofSoundGetSpectrum(bands);

}




void ofApp::draw() {
    ofSetColor(255);
    //cam.draw(0, 0);
    ofSetLineWidth(2);
    contourFinder.draw();
 
    

    
        
        
    
    //drop
    ofSetColor(255);
        for (int i = 0; i <= contourFinder.size() ; i++)
        {
            
            drops[i].draw();
            if (!contourFinder.size()){
                water.play();
            }
        }
    
    
    
    //gui
    gui.draw();
    
    //ofTranslate(1, 2000);
    //ofFill();
   
    //ofSetColor(255);
    //ofDrawRectangle(-3, -3, 64+6, 64+6);
    //ofSetColor(targetColor);
    //ofDrawRectangle(0, 0, 64, 64);
}

void ofApp::mousePressed(int x, int y, int button) {
    targetColor = cam.getPixels().getColor(x, y);
}
