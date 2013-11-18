#pragma once
#ifndef _OF_SEND_SERIAL 
#define _OF_SEND_SERIAL

#include "ofxOsc.h"
#include "ofMain.h"

#define PORT 8000 //connect the port to TouchOsc

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void sendMessages();
        ofSerial serial;
        ofxOscReceiver receiver;
        float oscPosf,oscPosb,oscPosl,oscPosr;
		float mouseButtonState1,mouseButtonState2;
        int tog;
};
#endif