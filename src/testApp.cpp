#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    serial.setup("/dev/tty.usbmodem411", 9600);
    // listen on the given port
	cout << "listening for osc messages on port " << PORT << "\n";
	receiver.setup(PORT);

}

//--------------------------------------------------------------
void testApp::update(){
    tog = 0;
    
    
    //-------------------------------------------Oriol,this part is to connect the TouchOSc om my phone.
    while(receiver.hasWaitingMessages()){
		// get the next message
		ofxOscMessage m;
		receiver.getNextMessage(&m);
        
		// check for mouse moved message
        
        if(m.getAddress() == "/1/push1"){
			mouseButtonState1 = m.getArgAsFloat(0);
		}
        
        
        if(m.getAddress() == "/1/push2"){
			mouseButtonState2 = m.getArgAsFloat(0);
		}

        
        if(m.getAddress() == "/1/fader1"){
			oscPosf = m.getArgAsFloat(0);
		}
        
        
        if(m.getAddress() == "/1/fader2"){
			oscPosb = m.getArgAsFloat(0);
		}
        
        
        
        if(m.getAddress() == "/1/fader3"){
			oscPosl = m.getArgAsFloat(0);
		}
	}
    
    //-------------------------------------------here is two judgements to decide the car forth or back
    if(mouseButtonState1 == 1){
        tog = 1;
    }else if(mouseButtonState2 == 1){
        tog = 2;
    }
    cout<<mouseButtonState1<<endl;
    cout<<mouseButtonState2<<endl;
    
    //-------------------------------------------this is the part that send messages to arduino side
    serial.writeByte(tog);
}

//--------------------------------------------------------------
void testApp::draw(){
 

}
//--------------------------------------------------------------

void testApp::sendMessages(){


    
}
//--------------------------------------------------------------

void testApp::keyPressed(int key){
    serial.writeByte(key);


}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

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