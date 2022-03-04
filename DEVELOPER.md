Developer name: Ben Schroeder

main.c

integrates the function gensine within gensnd



main2.c

main2 is an implementation of the numpad and silence functions within gensnd
in order to create a phone dialing noise



main1b.c

main1b is an implementation of the genSilence and genDTMF2 functions within gensnd in order to create a phone dialing noise



gensnd.h:

struct sound
A struct defined in order to store sound waves
samples - a float array containing the individual values of the sound
length - the size of the array samples
rate - the sample rate of the sound



gensnd.c:

gensine
given a sample rate, a frequency, and a duration will produce a soundwave
double sampleRate - sample rate given in hertz
double frequency - frequency given in hertz
double time - given in seconds

numpad
given a char input (key) numpad will output the tone given by that key press
char key - the corresponding key on a numpad

silence
given a sampleRate, and duration will create silence within the output
double sampleRate - the sample rate in hertz
double time - duration of the silence in seconds

gensine2
given hertz, sample sample_rate, and duration will return a pointer to a sound containing the sine wave
float hertz - the frequency of the sound in hertz
float sample_rate - the sample rate in hertz
float duration - duration of the sound in seconds

genDTMF2
given a key, a sample_rate, and a duration a sound will be created with the sine wave to the corresponding key press
char key - the corresponding key on a numpad
float sample_rate - the sample rate
float duration - the time in seconds of the sound

genSilence
given a sampleRate, and duration will create silence as a sound and return it
float sampleRate - the sample rate in hertz
float time - duration of the silence in seconds
