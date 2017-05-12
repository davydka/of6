#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);

    shadertoy.load("shaders/shader.frag");
    ofImage img;
    img.load("shaders/tex04.jpg");

    ofImage img0;
    img0.load("noise.png");
    myPlayer.load("britney.webm");
    myPlayer.play();
    ///*
    ofTexture tex;
    tex.allocate(img0.getWidth(), img0.getHeight(), GL_RGBA, false); // fourth parameter is false to avoid generation of a GL_TEXTURE_2D_RECTANGLE texture - we don't want this.
    tex.loadData(img0.getPixels());
    tex.generateMipmap();
    tex.setTextureWrap(GL_REPEAT, GL_REPEAT);
    shadertoy.setTexture(1, tex);
    ///*
    ofTexture texM;
    texM.allocate(img.getWidth(), img.getHeight(), GL_RGBA, false); // fourth parameter is false to avoid generation of a GL_TEXTURE_2D_RECTANGLE texture - we don't want this.
    texM.loadData(img.getPixels());
    texM.generateMipmap();
    texM.setTextureWrap(GL_REPEAT, GL_REPEAT);
    shadertoy.setTexture(0, texM);

    //ofSetFrameRate(60);
    shadertoy.setAdvanceTime(true);
    shadertoy.setUseMouse(true);
}

//--------------------------------------------------------------
void ofApp::update(){

	myPlayer.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
    shadertoy.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());

	ofSetColor(255, 0, 255);
	stringstream reportStream;
	reportStream << "fps: " << ofGetFrameRate() << endl;
	ofDrawBitmapString(reportStream.str(), 20, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key == 'f') {
        ofToggleFullscreen();
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
