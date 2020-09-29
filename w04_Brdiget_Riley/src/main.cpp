#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){

	ofGLWindowSettings settings;
	settings.setGLVersion(3,2);
	settings.setSize(706,800);
	settings.title = "Recreation of Bridget Riley's \"Straight Curve (1963)\"";
	ofCreateWindow(settings);


	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
