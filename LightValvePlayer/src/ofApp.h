#pragma once

#include "ofMain.h"
#include "ofxOscReceiver.h"

class ofApp : public ofBaseApp{
    
public:
    
public:
    void setup();
    void update();
    void draw();
    
    ofVideoPlayer vid;
    string vidName;
    
    ofxOscReceiver oscR;
    int port;
    
    int vidw;
    int vidh;
    
    bool black;
    bool white;
    bool showInfo;
    
    bool bLineNoise;
    ofFloatColor lineNoiseColor;
    
    bool bDotNoise;
    ofFloatColor dotNoiseColor;
    
};
