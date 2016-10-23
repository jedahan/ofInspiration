#include "ofApp.h"

void ofApp::setup(){
    std::string url = "http://ofxaddons.com/api/v1/repos";
    
    if (!repos.open(url)) {
        ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
    }
    
    font.load("inconsolata_powerline.otf", 32);
    
    
    ofApp::inspire();
}

void ofApp::inspire() {
    int repo_size = repos.size();
    this->foo = (int) ofRandom(repo_size);
    this->bar = (int) ofRandom(repo_size);
    while (foo == bar) { this->foo = (int) ofRandom(repo_size); }
}

void ofApp::draw(){
    ofBackground(0);

    std::string foo_name = repos[foo]["name"].asString();
    ofRectangle foo_box = font.getStringBoundingBox(foo_name, 0, 0);
    
    ofSetColor(255);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight()/2);
    
    ofSetColor(0);
    font.drawString(foo_name, (ofGetWidth()-foo_box.width)/2, ofGetHeight()*1/4);
    
    
    std::string bar_name = repos[bar]["name"].asString();
    ofRectangle bar_box = font.getStringBoundingBox(bar_name, 0, 0);
    
    ofSetColor(0);
    ofDrawRectangle(0, ofGetHeight()/2, ofGetWidth(), ofGetHeight());
    
    ofSetColor(255);
    font.drawString(bar_name, (ofGetWidth()-bar_box.width)/2, ofGetHeight()*3/4);
}

void ofApp::keyPressed(int key){
    ofApp::inspire();
}

void ofApp::mouseReleased(int x, int y, int button){
    ofApp::inspire();
}
