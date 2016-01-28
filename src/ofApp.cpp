#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(120);
    cam.setup(640, 480);
    smile.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
    if(cam.isFrameNew()) {
        smile.update(cam);
        if(smile.getFaceFound()) {
            float cur = smile.getSmileAmount();
            graph.add(cur);
            ofLog() << graph.getNormalized(cur);
            if(cur > 100) {
                ofxNotification(":-)",
                                "Smile is the best make-up.");
            }
        }
    }
}


//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    cam.draw(0, 0);
    smile.draw();
    
    ofTranslate(10, 10);
    ofSetColor(0);
    ofDrawRectangle(0, 0, 210, 40);
    
    ofSetColor(255);
    ofDrawBitmapString("Smile from ear to ear.", 10, 25);
    
}



