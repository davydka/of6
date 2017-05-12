#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
    ofGLWindowSettings settings;
    settings.setGLVersion(3, 2);    // <--- ofxShadertoy NEEDS the GL Programmable Renderer
    settings.width = 1920;
    settings.height = 1440;
    ofCreateWindow(settings);       // <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
