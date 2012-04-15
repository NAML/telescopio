#include "testApp.h"
using namespace ofxPm;

//--------------------------------------------------------------
void testApp::setup(){
	
	debug = false;
    showMovie = false;
    delayAlpha = 0;
    
	
	// camara
	grabber.listDevices();
	grabber.initGrabber(640,480);
	cout << grabber.getFps();
	// buffer
    buffer.setup(grabber, 60 * 10);         // cuantos frames quiero guardar
	// render realtime para debug
	realtime.setup(buffer);
	// un playhead para recorrer el buffer	
	playHead.setup(buffer);
	playHead.setDelay(40 * 10000 * 10);  // fps * 10000 * segDeDelay 	
//	delayed.setup(playHead);			 // el delay se activa cuando tiene sufientes frames para mostrarlo
	
	// la peli
	movie.loadMovie("clip.mov");
    
	// eventos a los que necesito estar atento
	
	// delay listo para reproducir
	
	
	// alguien pulso el boton
	//				fade in delay
	

	
	ofAddListener( trigger.end_E, this, &testApp::evento);
	ofBackground(0);
	ofEnableAlphaBlending();
	
}

//--------------------------------------------------------------
void testApp::update(){

	grabber.update();

	if (movie.isPlaying()) {
		movie.update();
	}
	
	if (buffer.isFull()) {
	//	buffer.stop();
	}

	
    
}

void testApp::evento(int &id){
    cout << "bang" << endl;
  
   
}





//--------------------------------------------------------------
void testApp::draw(){
	
	ofBackground(0, 0, 0, 0);
	ofSetColor(255,255,255, tweencubic.update());
	ofRect(0, 0, 30, 30	);

	// la manera apropiada de dibujar un buffer es sacando la referencia a la ofTexture que usa
	// para eso tengo que pasar por el frame
	// obtengo un puntero para el frame actual
	VideoFrame * frame = playHead.getNextVideoFrame();
	// y de ese frame obtengo una REFERENCIA a la ofTexture. (recuerda peque–o padawan: una referencia es el referente) :)
	frame->getTextureRef().draw(0, 0, 800, 600);
	
	
	
	if (debug) {
		//	grabber.draw() does not work
		//	grabber.draw(0,0,320,240);
		
		playHead.draw();
		buffer.draw();
		
		realtime.draw(0,0,160,120);
		delayed.draw(160,0,160,120);
		movie.draw(320, 0, 160, 120);
		
	}
	
	// ofDrawBitmapString("VideoFrame pool size: " + ofToString(VideoFrame::getPoolSize(VideoFormat(640,480,3))),20,ofGetHeight()-20);

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
	//	movie.play();
	//	showMovie = true;
		
		// fade in delay
		tweencubic.setParameters(1,easingcubic,ofxTween::easeOut,0,255,2000,0);
		
		
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
