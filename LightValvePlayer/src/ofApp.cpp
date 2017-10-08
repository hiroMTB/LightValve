#include "ofApp.h"

void ofApp::setup(){
    
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    
    // video load
    vidName = "LV_layer1_n90.mov";
    vid.load(vidName);
    vid.setLoopState(OF_LOOP_NONE);
    
    
    //	vid.setSpeed(10);
    
    vidw = 1280;
    vidh = 1024;
    
    // osc
    port = 1111;
    oscR.setup(port);	// should be change
    
    black = white = false;
    showInfo = false;
    
    bLineNoise = true;
    lineNoiseColor.set(1,1,1,0.6);
    
    bDotNoise = false;
    dotNoiseColor.set(0);
    
    ofHideCursor();
}

void ofApp::update(){
    
    while (oscR.hasWaitingMessages()) {
        ofxOscMessage m;
        oscR.getNextMessage(&m);
        
        string address = m.getAddress();
        if(address=="/play"){
            vid.play();
        }else if(address=="/stop"){
            vid.stop();
        }else if(address=="/pause"){
            vid.setPaused(true);
        }else if(address=="/backToTop"){
            vid.setPosition(0);
        }else if(address=="/black"){
            black = !black;
        }else if(address=="/white"){
            white = !white;
        }else if(address=="/fullscreen"){
            ofToggleFullscreen();
        }else if( address=="/1280x1024" ){
            ofSetWindowShape(1280, 1024);
            ofSetWindowPosition(0, 0);
        }else if(address=="/info"){
            showInfo = !showInfo;
        }else if(address=="/lineNoise"){
            bLineNoise = !bLineNoise;
        }else if(address=="/setLineNoiseColor"){
            float r = m.getArgAsFloat(0);
            float g = m.getArgAsFloat(1);
            float b = m.getArgAsFloat(2);
            float a = m.getArgAsFloat(3);
            lineNoiseColor.set(r,g,b,a);
        }else if(address == "/dotNoise"){
            bDotNoise = !bDotNoise;
        }else if(address == "/setDotNoiseColor"){
            float r = m.getArgAsFloat(0);
            float g = m.getArgAsFloat(1);
            float b = m.getArgAsFloat(2);
            float a = m.getArgAsFloat(3);
            dotNoiseColor.set(r,g,b,a);
            
        }else if(address == "/setPositionMs"){
            float totalDurationMs = vid.getDuration();
            float pct = (float) (m.getArgAsInt32(0)) / totalDurationMs;
            vid.setPosition(pct);
        }
        
        cout << "Receive OSC at " + address << endl;
        
    }
    
    vid.update();
}

void ofApp::draw(){
    
    ofDisableAntiAliasing();
    
    int w = ofGetWidth();
    int h = ofGetHeight();
    ofBackgroundHex(0xFFFFFF);
    ofSetColor(255,255,255);
    vid.draw(0, 0, w, h);
    
    if(bLineNoise){
        
        ofSetColor(lineNoiseColor);
        int n= ofRandom(100, 300);
        
        for(int i=0; i<n; i++){
            
            int x1 = ofRandom(-ofGetWidth()/2, ofGetWidth()*1.5);
            int x2 = ofRandom(-ofGetWidth()/2, ofGetWidth()*1.5);
            
            int y1 = ofRandom(-ofGetHeight()/2, ofGetHeight()*1.5);
            int y2 = ofRandom(-ofGetHeight()/2, ofGetHeight()*1.5);
            
            int z1 = 0; //ofRandom(-10, 10);
            int z2 = 0; //ofRandom(-10., 10);
            
            ofDrawLine(x1, y1, x2, y2);
        }
    }
    
    	if(bDotNoise){
    		ofSetColor(dotNoiseColor);
    		for(int i=0; i<1000; i++){
                float x = ofRandom(0, ofGetWidth());
                float y = ofRandom(0, ofGetHeight());
                int z = 0;
                ofDrawCircle(x, y, 1);
    		}
    	}
    
    if(black){
        ofSetColor(0,0,0);
        ofRect(0,0,w, h);
    }
    if(white){
        ofSetColor(255,255,255);
        ofRect(0,0,w, h);
    }
    if(showInfo){
        ofSetColor(0,0,0,150);
        ofRect(0, 0, 300, ofGetHeight());
        
        
        
        
        // FIX
        // FIX
        // FIX
        // FIX
        
        int seconds = vid.getPosition()*vid.getDuration();
        
        ofSetColor(255);
        ofDrawBitmapString("info", 10, 20);
        ofDrawBitmapString("FPS: "+ofToString(ofGetFrameRate()), 10, 40);
        ofDrawBitmapString("OSC port: "+ofToString(port), 10, 55);
        ofDrawBitmapString("video position: "+ofToString(seconds/60) + " min " + ofToString(seconds%60) + " sec", 10, 70);
        ofDrawBitmapString("vid name: "+vidName, 10, 85);
    }
    
}

