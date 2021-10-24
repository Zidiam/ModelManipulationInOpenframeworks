#include "ofApp.h"

/*
Loads in the same 3D penguin model in various file types. Demonstrates how to load in a model using both ofMesh and ofxAssimpModelLoader.
*/

//--------------------------------------------------------------
void ofApp::setup() {
    ofBackground(255, 255, 255);

    ofSetVerticalSync(true);

    modelName = "car";

    // load the first model
    model.loadModel(modelName + ".dae", 20);
    // model info
    curFileInfo = ".dae";

    // this loads in the model directly into a mesh
    // ofMesh can only read in .plys that are in the ascii and not in the binary format.
    bUsingMesh = false;
    mesh.load(modelName + ".ply");
    // you can create as many rotations as you want
    // choose which axis you want it to effect
    // you can update these rotations later on
    // these rotation set the model so it is oriented correctly
    model.setScale(0.9, 0.9, 0.9);
    model.setRotation(2, 180, 0, 0, 1);
    cam.setDistance(700);
    light.setPosition(cam.getPosition());

    //set help text to display by default
    bHelpText = true;

    //GUI Setup
    gui.setup();
    gui.setDefaultBackgroundColor(ofColor(255, 255, 255));
    gui.add(label1.setup("label", "Model GUI"));
    gui.add(toggle1.setup("Car", true));
    gui.add(toggle2.setup("Spaceship", false));
    gui.add(toggle4.setup("Dog", false));
    gui.add(button1.setup("Press to Change Model"));
    gui.add(vec3Slider1.setup("Model Position", model.getPosition(), ofVec3f(-1000, -1000, -1000), ofVec3f(1000, 1000, 1000)));
    gui.add(vec3Slider2.setup("Light Position", light.getPosition(), ofVec3f(-1000, -1000, -1000), ofVec3f(1000, 1000, 1000)));
    gui.add(toggle3.setup("Lock Light With Camera", true));

    label1.setBackgroundColor(ofColor(255, 255, 255, 0));
    toggle1.setBackgroundColor(ofColor(255, 255, 255, 0));
    toggle2.setBackgroundColor(ofColor(255, 255, 255, 0));
    toggle4.setBackgroundColor(ofColor(255, 255, 255, 0));
    button1.setBackgroundColor(ofColor(255, 255, 255, 0));
    vec3Slider1.setBackgroundColor(ofColor(255, 255, 255, 0));
    vec3Slider2.setBackgroundColor(ofColor(255, 255, 255, 0));
    toggle3.setBackgroundColor(ofColor(255, 255, 255, 0));
}

//--------------------------------------------------------------
void ofApp::update() {
    if (toggle3) {
        light.setPosition(cam.getPosition());
    }
    else {
        light.setPosition(vec3Slider2->x, vec3Slider2->y, vec3Slider2->z);
    }
    model.setPosition(vec3Slider1->x, vec3Slider1->y, vec3Slider1->z);
    if (button1) {
        if (toggle1) {
            modelName = "car";
            model.loadModel(modelName + ".dae", 20);
            curFileInfo = ".dae";
            mesh.load(modelName + ".ply");
            model.setScale(0.9, 0.9, 0.9);
            model.setRotation(2, 180, 0, 0, 1);
            cam.setDistance(700);
            light.setPosition(cam.getPosition());
        }
        else if (toggle2) {
            modelName = "spaceship";
            model.loadModel(modelName + ".obj", 20);
            curFileInfo = ".obj";
            mesh.load(modelName + ".obj");
            model.setScale(0.9, 0.9, 0.9);
            model.setRotation(2, 180, 0, 0, 1);
            cam.setDistance(700);
            light.setPosition(cam.getPosition());
        }
        else if (toggle4) {
            modelName = "dog";
            model.loadModel(modelName + ".obj", 20);
            curFileInfo = ".obj";
            mesh.load(modelName + ".obj");
            model.setScale(0.9, 0.9, 0.9);
            model.setRotation(2, 180, 0, 0, 1);
            cam.setDistance(700);
            light.setPosition(cam.getPosition());
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    gui.draw();

    // so the model isn't see through.
    ofEnableDepthTest();

    light.enable();

    cam.begin();
    ofColor(255, 255);
    if (bUsingMesh) {
        // draws the ply file loaded into the mesh is you pressed 6
        meshNode.transformGL();
        mesh.draw();
        meshNode.restoreTransformGL();
    }
    else {
        // draws all the other file types which are loaded into model.
        model.drawFaces();
    }
    cam.end();

    light.disable();

    ofDisableDepthTest();

    // display help text if it is enable
    if (bHelpText) {
        stringstream ss;
        ss << "FPS: " << ofToString(ofGetFrameRate(), 0) << endl << endl;
        ofDrawBitmapString(ss.str().c_str(), 20, 20);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}