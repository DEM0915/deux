#ifndef fish_hpp
#define fish_hpp

#include "ofMain.h"

class Fish {
    
public:
    
    Fish();
    Fish( ofPoint _pos, float _size, float _speed);
    
    void update ();
    void draw ();
    void xenoToPoint(float catchX, float catchY);
    float angleInDegrees;
    float prevAngleInDegrees;
    float catchUpSpeed;
    
    ofPoint pos;
    float size;
    float sinMult;
    float speed;
    
    vector<float> rectH;
    vector<float> posY;
    
};

#endif
