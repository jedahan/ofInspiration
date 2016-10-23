#pragma once

#include "ofMain.h"
#include "ofxJSON.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void draw();
    
        void inspire();

		void keyPressed(int key);
		void mouseReleased(int x, int y, int button);
    
    private:
        ofxJSONElement repos;
        int foo, bar;
        ofTrueTypeFont font;
		
};
