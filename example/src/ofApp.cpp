#include "ofApp.h"

//--------------------------------------------------------------
ofVec3f mni2tal(ofVec3f inpoints){

	ofVec3f out;
	ofVec3f upT(0.99, 0.97, 0.92);
	ofVec3f downT(0.99, 0.97, 0.84);
	
	if (inpoints.z > 0){
		out = inpoints * upT;
	}else{
		out = inpoints * downT;
	}
	
	out = out.rotateRad(0.05, ofVec3f(-1,0,0));
	
	return out;
}
//--------------------------------------------------------------
ofVec3f tal2mni(ofVec3f inpoints){

	ofVec3f out;
	ofVec3f upT(0.99, 0.97, 0.92);
	ofVec3f downT(0.99, 0.97, 0.84);
	
	out = inpoints.rotateRad(0.05, ofVec3f(1,0,0));
	
	if (inpoints.z > 0){
		out = out / upT;
	}else{
		out = out / downT;
	}
	
	return out;
}

//--------------------------------------------------------------
void ofApp::setup(){

	ofVec3f coord(10, 12, 14);
	cout << "initial " << coord << endl;
	cout << "mni2tal " << mni2tal(coord) << endl;
	cout << "tal2mni " << tal2mni(mni2tal(coord)) << endl;
	
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
