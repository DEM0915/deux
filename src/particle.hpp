//
//  particle.hpp
//  Dali
//
//  Created by DEM0915 on 15/11/17.
//
//

#ifndef particle_hpp
#define particle_hpp

#include "ofMain.h"


class particle
{
    public :
    particle() ;
    particle( ofPoint _position , ofColor _color )
    {
        position = _position ;
        color = _color ;
        velocity = ofPoint ( ofRandom ( -5 , 5 ) , ofRandom ( -5 , 5 ) ) ;
        spawnPoint = _position ;
    }
    
    ofPoint position , velocity ;
    ofPoint acceleration ;          
    ofPoint spawnPoint ;
    ofColor color ;
};

#endif /* particle_hpp */
