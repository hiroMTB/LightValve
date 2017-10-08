#include "ofMain.h"
#include "ofApp.h"


int main( ){

    ofGLFWWindowSettings s;
    s.setPosition( ofVec2f(0,0));
    s.title = "LV v3";
    s.setGLVersion(4, 1);
    s.multiMonitorFullScreen = false;
    s.windowMode = OF_WINDOW;
    s.numSamples = 1;
    s.width = 1280;
    s.height = 1024;
    s.monitor = 1;
    s.decorated = false;
    ofCreateWindow(s);
    
	//ofSetupOpenGL(1280/2, 1024/2, OF_WINDOW);
	ofRunApp( new ofApp());

}
