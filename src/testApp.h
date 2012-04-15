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
    
    
	void tweenParseEvent(int &id);
	
	ofxPm::VideoGrabber         grabber;
	ofxPm::VideoBuffer          buffer;
	ofxPm::VideoHeader          playHead;
	
	ofxPm::BasicVideoRenderer   realtime;
	ofxPm::VideoRenderer		delayed;
	
	ofxPm::VideoFrame*			frame;			
  
	bool showMovie ;
	
	
	ofxTween            camaraAlpha;
	ofxEasingCubic      easingcubic;
	ofxTween            triggerPelicula;
	ofxEasingLinear     linear;
    
	ofVideoPlayer 		movie;
	bool	debug;
    
	
	
    
};
