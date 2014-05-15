#pragma once

#include "ofMain.h"
#include "AngrySparrow.h"

class ofApp : public ofBaseApp{

    
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
    
    void audioOut(float * input, int bufferSize, int nChannels);
    
    
    ofSoundStream soundStream;
    
    float 	pan;
    int		sampleRate;
    bool 	bNoise;
    float 	volume;
    
    vector <float> lAudio;
    vector <float> rAudio;
    
    std::vector<float> targetVec, freqVec, modVec, adderVec, multiVec;
    AngrySparrow::Sine mod(&modVec, &freqVec);
    AngrySparrow::Sine carrier(&targetVec, &modVec);
    AngrySparrow::Multiplier multiplier(&modVec, &adderVec);
    AngrySparrow::Adder adder(&modVec, &multiVec);
    AngrySparrow::DSP dsp;
    
    //------------------- for the simple sine wave synthesis
    float 	targetFrequency;
    float 	phase;
    float 	phaseAdder;
    float 	phaseAdderTarget;
};
