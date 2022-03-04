#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "gensnd.h"

/*
* Ben Schroeder
*
* gensnd.c contains functions which produce sound waves based on the frequency, sample rate, and duration
*/

/*
* gensine2
* given hertz, sample sample_rate, and duration will return a pointer to a sound containing the sine wave
*
* float hertz - the frequency of the sound in hertz
* float sample_rate - the sample rate in hertz
* float duration - duration of the sound in seconds
*/
sound *gensine(float hertz, float sample_rate, float duration) {
    //Variable declarations
    sound *sineWave = malloc(sizeof(sound));
    int i;

    //Basic values assigned to sineWave
    sineWave->length = sample_rate * duration;
    sineWave->rate = sample_rate;
    sineWave->samples = malloc(sineWave->length * sizeof(float));

    //modification of the formula explained within the dev document in order to iterate through an array
    for (i = 0; i < sineWave->length; i ++) {
        float f = sin(((i * 2 * M_PI) / sample_rate) * hertz);
        sineWave->samples[i] = f;
    }

    return sineWave;
}

/*
* genDTMF2
* given a key, a sample_rate, and a duration a sound will be created with the sine wave to the corresponding key press
*
* char key - the corresponding key on a numpad
* float sample_rate - the sample rate
* float duration - the time in seconds of the sound
*/
sound *genDTMF(char key, float sample_rate, float duration) {
    //variable declarations
    sound *sineWave = malloc(sizeof(sound));
    int i;
    double freq1 = 0;
    double freq2 = 0;

    //Basic values assigned to sineWave
    sineWave->length = sample_rate * duration;
    sineWave->rate = sample_rate;
    sineWave->samples = malloc(sineWave->length * sizeof(float));

    //locates the row the key is in and assigns a frequency to freq1
    if (key == '1' || key == '2' || key == '3' || key == 'A' || key == 'a')
        freq1 = 697;
    if (key == '4' || key == '5' || key == '6' || key == 'B' || key == 'b')
        freq1 = 770;
    if (key == '7' || key == '8' || key == '9' || key == 'C' || key == 'c')
        freq1 = 852;
    if (key == '*' || key == '0' || key == '#' || key == 'D' || key == 'd')
        freq1 = 941;

    //locates the column the key is in and assigns a frequency to freq2
    if (key == '1' || key == '4' || key == '7' || key == '*')
        freq2 = 1209;
    if (key == '2' || key == '5' || key == '8' || key == '0')
        freq2 = 1336;
    if (key == '3' || key == '6' || key == '9' || key == '#')
        freq2 = 1477;
    if (key == 'A' || key == 'B' || key == 'C' || key == 'D' || key == 'a' || key == 'b' || key == 'c' || key == 'd')
        freq2 = 1633;

    //generates the sound waves based of freq1 and freq2
    sound *sound1 = gensine2(freq1, sample_rate, duration);
    sound *sound2 = gensine2(freq2, sample_rate, duration);

    //modification of the formula explained within the dev document in order to iterate through an array
    for (i = 0; i < sineWave->length; i ++) {
        sineWave->samples[i] = (sound1->samples[i] + sound2->samples[i]) / 2;
    }

    //frees the memory allocated in malloc
    free(sound1);
    free(sound2);

    return sineWave;
}


/*
* genSilence
* given a sampleRate, and duration will create silence as a sound and return it
*
* float sampleRate - the sample rate in hertz
* float time - duration of the silence in seconds
*/
sound * genSilence(float sample_rate, float duration) {
    //variable declarations
    sound* sineWave = malloc(sizeof(sound));
    int i;

    //Basic values assigned to sineWave
    sineWave->length = sample_rate * duration;
    sineWave->rate = sample_rate;
    sineWave->samples = malloc(sineWave->length * sizeof(float));

    //modification of the formula explained within the dev document in order to iterate through an array
    for (i = 0; i < sineWave->length; i ++) {
        sineWave->samples[i] = 0;
    }

    return sineWave;
}

sound* genSquare(float hertz, float sample_rate, float duration) {
    //Variable declarations
    sound *sineWave = malloc(sizeof(sound));
    int i;

    //Basic values assigned to sineWave
    sineWave->length = sample_rate * duration;
    sineWave->rate = sample_rate;
    sineWave->samples = malloc(sineWave->length * sizeof(float));

    //modification of the formula explained within the dev document in order to iterate through an array
    for (i = 0; i < sineWave->length; i ++) {
        float time = i / sample_rate * freq;
        float t = time - (int) time;
        if (t < 0.5)
            sineWave->samples[i] = -1;
        else
            sineWave->samples[i] = 1;
    }

    return sineWave;
}

sound* genTriangle(float hertz, float sample_rate, float duration) {
    //Variable declarations
    sound *sineWave = malloc(sizeof(sound));
    int i;

    //Basic values assigned to sineWave
    sineWave->length = sample_rate * duration;
    sineWave->rate = sample_rate;
    sineWave->samples = malloc(sineWave->length * sizeof(float));

    //modification of the formula explained within the dev document in order to iterate through an array
    for (i = 0; i < sineWave->length; i ++) {
        float time = i / sample_rate * freq;
        float t = time - (int) time;
        if (t < 0.5)
            sineWave->samples[i] = 4 * t -1;
        else
            sineWave->samples[i] = -4 * t + 3;
    }

    return sineWave;
}

sound* genSawtooth(float hertz, float sample_rate, float duration) {
    //Variable declarations
    sound *sineWave = malloc(sizeof(sound));
    int i;

    //Basic values assigned to sineWave
    sineWave->length = sample_rate * duration;
    sineWave->rate = sample_rate;
    sineWave->samples = malloc(sineWave->length * sizeof(float));

    //modification of the formula explained within the dev document in order to iterate through an array
    for (i = 0; i < sineWave->length; i ++) {
        float time = i / sample_rate * freq;
        float t = time - (int) time;
        sineWave->samples[i] = 2 * t -1;
    }

    return sineWave;
}
