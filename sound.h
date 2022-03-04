#ifndef SOUND_H
#define SOUND_H

/*
* sound
* A struct defined in order to store sound waves
*
* samples - a float array containing the individual values of the sound
* length - the size of the array samples
* rate - the sample rate of the sound
*/
typedef struct sound_t {
    float * samples;
    int length;
    float rate;
} sound;

#endif
