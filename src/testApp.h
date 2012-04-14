#pragma once

#include "ofMain.h"
#include "ofxPlaymodes.h"
#include "ofxTween.h"
#include "ofEvents.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
        void evento(int &id);
		
		ofxPm::VideoGrabber         grabber;
		ofxPm::VideoBuffer          buffer;
		ofxPm::VideoHeader          header;
		
        ofxPm::BasicVideoRenderer   realtime;
        ofxPm::BasicVideoRenderer   delayed;
    
        float delayAlpha;
         bool showMovie ;
        ofxEasingCubic      easingcubic;
        ofxTween            tweencubic;

        ofxTween            trigger;
        ofxEasingLinear     linear;
    
        ofVideoPlayer 		movie;
	bool	debug;
    
    
    
};
