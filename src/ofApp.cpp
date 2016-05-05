#include "ofApp.h"

void ofApp::setup(){
    
    ofBackground(0) ;
    pic.load("Fancypixel.png") ;
    ofSetFullscreen(true);
    ofHideCursor();
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    mySound.load("Kraftwerk - The Robots-2.mp3");
    mySound.play();
    mySound.setPaused(true);
    
    
    sampling = 2 ;
    unsigned char * pixels = pic.getPixels() ;
    int w = pic.getWidth() ;
    int h = pic.getHeight() ;
    
    int xOffset = (ofGetWidth() - w ) /2 ;
    int yOffset = (ofGetHeight() - h ) /2 ;
    
    for ( int x = 0 ; x < w ; x+=sampling )
    {
        
        for ( int y = 0 ; y < h ; y+=sampling )
        {
        
            int index = ( y * w + x ) * 3 ;
            ofColor color ;
            color.r = pixels[index] ;
            color.g = pixels[index+1] ;
            color.b = pixels[index+2] ;
            particles.push_back( particle ( ofPoint ( x + xOffset , y + yOffset ) , color ) ) ;
        }
    }
    
    
    ofSetFrameRate( 40 ) ;
    numParticles = (pic.getWidth() * pic.getHeight())/sampling;
    
    cursorMode = 0 ;
    forceRadius = 64 ;
    friction = 0.89 ;
    springFactor = 0.19 ;
    springEnabled = true ;

}


void ofApp::update(){
    
    ofPoint diff ;
    float dist ;
    float ratio ;
    const ofPoint mousePosition = ofPoint( mouseX , mouseY ) ;
    
    std::vector<particle>::iterator p ;
    for ( p = particles.begin() ; p != particles.end() ; p++ )
    {
        ratio = 1.0f ;
        p->velocity *= friction ;
        
        p->acceleration = ofPoint() ;
        diff = mousePosition - p->position ;
        dist = ofDist( 0 , 0 , diff.x , diff.y ) ;
        
        if ( dist < forceRadius )
        {
            ratio = -1 + dist / forceRadius ;
            
            if ( cursorMode == 0 )
                p->acceleration -= ( diff * ratio) ;
            
            else
                p->acceleration += ( diff * ratio ) ;
        }
        
        if ( springEnabled )
        {
    
            p->acceleration.x += springFactor * (p->spawnPoint.x - p->position.x);
            p->acceleration.y += springFactor * (p->spawnPoint.y - p->position.y) ;
        }
        
        p->velocity += p->acceleration * ratio ;
        p->position += p->velocity ;
    }
    
    
    
    //music
    if(mousePos.distance(pastMousePos) > 0){
    
        mySound.setPaused(false);
    }
    else{
        mySound.setPaused(true);
    }

    pastMousePos.set(mouseX, mouseY);
    
    //Cursor
    myFish.update();
    
}

void ofApp::draw(){
    
    //pic pixel
    glBegin(GL_POINTS);
    
    std::vector<particle>::iterator p ;
    for ( p = particles.begin() ; p != particles.end() ; p++ )
    {
        glColor3ub((unsigned char)p->color.r,(unsigned char)p->color.g,(unsigned char)p->color.b);
        glVertex3f(p->position.x, p->position.y , 0 );
    }
    
    glEnd();
    
    //Cursor
    ofSetColor(253, 253, 253, 25);
    myFish.xenoToPoint(mouseX, mouseY);
    myFish.draw();
    
}

void ofApp::keyPressed(int key){
    
    switch ( key )
    
    {
        case 'w':
        case 'W':
            cursorMode = ( cursorMode + 1 > 1 ) ? 0 : 1 ;
            break ;
            
            
        case 'j':
        case 'J':
            springEnabled = !springEnabled ;
            break ;
   
    }


}

void ofApp::mouseMoved(int x, int y ){
    
    mousePos.set(x,y);

}