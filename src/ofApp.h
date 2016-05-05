#include "ofMain.h"
#include "particle.hpp"
#include "fish.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void mouseMoved(int x, int y );

    
    
    
        ofImage pic ;
        int sampling ;
        vector<particle> particles ;
        int numParticles ;
    
    
        bool springEnabled ;
        float forceRadius ;
        float friction ;
        float springFactor ;
        int cursorMode ;
    
    
        ofSoundPlayer mySound;
        ofPoint mousePos, pastMousePos;
    
        Fish myFish = Fish (ofPoint (ofGetWindowWidth()/2, ofGetWindowHeight()/2), ofRandom(25, 40), ofRandom(0.1, 0.5));
		
};
