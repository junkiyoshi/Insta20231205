#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateX(90);

	ofColor color;
	for (int i = 0; i < 1000; i++) {

		int z = (int)(ofRandom(-500, 500) + (ofGetFrameNum() * 10)) % 1000 - 500;
		int r = ofRandom(4);
		int p = r * 90;

		color.setHsb(ofRandom(r * 64, r * 64 + 32), 230, 255);
		ofSetColor(color);

		ofPushMatrix();
		ofRotateZ(z * 0.5 + p + ofGetFrameNum());

		z += ofRandom(-25, 25);
		ofDrawSphere(glm::vec3(ofRandom(100, 200), 0, z), 10);

		ofPopMatrix();
	}

	this->cam.end();

	/*
	int start = 150;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}