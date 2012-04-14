#include "testApp.h"
using namespace ofxPm;

//--------------------------------------------------------------
void testApp::setup(){
	
	debug = true;
    
	grabber.listDevices();
	grabber.initGrabber(640,480);
    buffer.setup(grabber, 30 * 10);         // cuantos frames quiero guardar
	buffer.resume();
	header.setup(buffer);
	
	realtime.setup(buffer);
	
	//movie.loadMovie("fingers.mov");
    
	// eventos a los que necesito estar atento
	
	// delay listo para reproducir
	
	
	// alguien pulso el boton
	//				fade in delay
	//					
    
	
	ofAddListener( trigger.end_E, this, &testApp::evento);
    
    showMovie = false;
    
    
	//	
	// 	
    
    delayAlpha = 0;
	
    
	//    delayed.setup(header);
    
	ofBackground(0);
}

//--------------------------------------------------------------
void testApp::update(){
	grabber.update();

	
	//  cout << trigger.update() << endl;
	//    trigger.update();
	//    if(showMovie) movie.idleMovie();
	
    
}

void testApp::evento(int &id){
    cout << "bang" << endl;
    movie.play();
    showMovie = true;
}





//--------------------------------------------------------------
void testApp::draw(){
	
	//	ofBackground(255, 255, 255, 255);
    // dibujo la capa delay
	
	//    ofPushMatrix();
	//    ofEnableAlphaBlending();    // turn on alpha blending
	
	
	
    
	//	ofSetColor(255,255,255,tweencubic.update());    // red, 50% transparent
	//	delayed.draw();
	
    if (showMovie) {
		//        movie.draw(0, 0, ofGetWindowWidth() , ofGetWindowHeight());
    }
	//	header.draw();
    
	
	if (debug) {
		header.draw();
		buffer.draw();
		realtime.draw();
	}
	
	// ofDrawBitmapString("VideoFrame pool size: " + ofToString(VideoFrame::getPoolSize(VideoFormat(640,480,3))),20,ofGetHeight()-20);
	
	
	
	//	grabber.draw() does not work
	//	grabber.draw(0,0,320,240);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
	if(key==' '){
		if(buffer.isStopped()){
			buffer.resume();
		}else{
			buffer.stop();
			
		}        
	}
	
    
    
    if(key == '0'){
        header.setPct(0);
        tweencubic.setParameters(0,easingcubic,ofxTween::easeOut,0,255,3000,0);
        trigger.setParameters(linear, ofxTween::easeOut, 0, 1, 9000, 0);
        buffer.stop();
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	float pct = float(x)/float(ofGetWidth());
	// header.setPct(pct);
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
	
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
	
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
	
}
