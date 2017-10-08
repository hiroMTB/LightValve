#pragma once

#include "ofMain.h"
#include "ofxOscReceiver.h"

class ofApp : public ofBaseApp{
    
public:
    
public:
    void setup();
    void update();
    void draw();
    
    // player func
    void play();
    void pause();
    void backToTop();
    void tobbleBlack();
    void tobbleWhite();
    void tobbleFullscreen();
    void set1280x1024();
    void tobbleInfo();
    void tobbleLineNoise();
    void setLineNoiseColor(float r, float g ,float b, float a);
    void tobbleDotNoise();
    void setDotNoiseColor(float r, float g ,float b, float a);
    void setPositionMs(int ms);
        
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
