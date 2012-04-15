#include "testApp.h"
using namespace ofxPm;

//--------------------------------------------------------------
void testApp::setup(){
	
	debug = false;
    showMovie = false;
 //   delayAlpha = 0;
    
	
	// camara
	grabber.listDevices();
	grabber.initGrabber(640,480);
	cout << grabber.getFps();
	// buffer
    buffer.setup(grabber, 30 * 10);         // cuantos frames quiero guardar
	// render realtime para debug
	realtime.setup(buffer);
	// un playhead para recorrer el buffer	
	playHead.setup(buffer);
	playHead.setDelay(30 * 10000 * 10);  // fps * 10000 * segDeDelay 	
	//	delayed.setup(playHead);			 // el delay se activa cuando tiene sufientes frames para mostrarlo
	
	// la peli
	movie.loadMovie("clip.mov");
	
	
	// los tween disparan un evento llamado "end_E" que trae como parametro el id del tween que lo lanzo
	// todos estos eventos van a estar parseados en tweenParseEvent
	ofAddListener( triggerPelicula.end_E, this, &testApp::tweenParseEvent);
	ofAddListener( camaraAlpha.end_E, this, &testApp::tweenParseEvent);

	
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

void testApp::tweenParseEvent(int &id){
	
    cout << "bang: " << id << endl;
	
	switch (id) {
		case 1:
			movie.play();
			showMovie = true;
			
			break;
		default:
			break;
	}
	
	
}





//--------------------------------------------------------------
void testApp::draw(){
	
	ofBackground(0, 0, 0, 0);
	ofSetColor(255,255,255, camaraAlpha.update());
	ofRect(0, 0, 30, 30	);
	
	// la manera apropiada de dibujar un buffer es sacando la referencia a la ofTexture que usa
	// para eso tengo que pasar por el frame
	// obtengo un puntero para el frame actual
	 frame = playHead.getNextVideoFrame();
	// y de ese frame obtengo una REFERENCIA a la ofTexture. (recuerda peque–o padawan: una referencia es el referente) :)	
	if(frame != NULL) frame->getTextureRef().draw(0, 0, 800, 600);
	// importante llamar a release sino leakea.
	// esto es porque usa un tipo de cola para guardar frames que necesita descargar
	// una vez que necesita el espacio
	frame->release();

	
	triggerPelicula.update();
	
	if (showMovie) {
		movie.draw(0, 0, 800, 600);
	}
	
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
		
		// fade in delay activa camara retrasada y trigger de video
		camaraAlpha.setParameters(		0,easingcubic	,ofxTween::easeOut	,0,255	,2000,0);
		triggerPelicula.setParameters(	1,linear		,ofxTween::easeOut	,0,1	,6000,0);
		
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
