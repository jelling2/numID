#include "ofApp.h"
#include "naive.hpp"

using namespace std;


ofImage screen;

vector<double> class_probs = {0.094833333333333339, 0.11183333333333334, 0.098500000000000004, 0.098833333333333328, 0.107, 0.087666666666666671, 0.098666666666666666, 0.10933333333333334, 0.094166666666666662, 0.099166666666666667};


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundColor(255, 255, 255);
    
    screen.allocate(112, 112, OF_IMAGE_GRAYSCALE);
    screen.setColor(ofColor::white);
    screen.update();
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
        screen.draw(0, 0);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'c') {
        clearScreen();
    }
    if (key == OF_KEY_RETURN) {
        Model model = load("//Users/Jake/Documents/training_probabilities");

        screen.resize(28, 28);
//        screen.save("out.jpg");
//        screen.draw(0,0);
        
        int result = classify(model, class_probs, screen);
        cout << result << endl;
        clearScreen();
        
//        ofDrawBitmapString(result, ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    for (auto e: expandPen(x, y)) {
        screen.setColor(e.first, e.second, ofColor::black);
        screen.update();
    }
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


void ofApp::clearScreen() {
    screen.setColor(ofColor::white);
    screen.update();
}






vector<pair<int, int>> ofApp::expandPen(int x, int y) {
    vector<pair<int, int>> brush;
    brush.push_back(make_pair(x, y));
    brush.push_back(make_pair(x + 1, y));
    brush.push_back(make_pair(x - 1, y));
    brush.push_back(make_pair(x, y + 1));
    brush.push_back(make_pair(x, y - 1));
    brush.push_back(make_pair(x + 1, y + 1));
    brush.push_back(make_pair(x + 1, y - 1));
    brush.push_back(make_pair(x - 1, y + 1));
    brush.push_back(make_pair(x - 1, y - 1));
    
    return brush;
}

