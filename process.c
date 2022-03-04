#include "process.h"

sound* mix(sound* s[], float w[], int c) {

    sound *mixWave = malloc(sizeof(sound));

    int i;
    int length = 0;

    for(i = 0; i < c; i++) {
        if (s[i]->length > length)
            length = s[i]->length;
    }

    //Basic values assigned to sineWave
    mixWave->length = length;
    mixWave->rate = s[0]->rate;
    mixWave->samples = malloc(mixWave->length * sizeof(float));

    int k = 0;
    float count = 0;

    for (i = 0; i < mixWave->length; i++) {
        count = 0;

        for (k = 0; k < c; k++)
            count += s[k]->samples[i] * w[k];

        mixWave->samples[i] = count;
    }

    return mixWave;
}

sound* modulate(sound* s1, sound* s2) {
    if (s1->length != s2->length)
        return null;

    sound *modWave = malloc(sizeof(sound));

    modWave->length = s1->length;
    modWave->rate = s1->rate;
    modWave->samples = malloc(modWave->length * sizeof(float));

    int i;

    for (i = 0; i < modWave->length; i++) {
        modWave->samples[i] = s1->samples[i] * s2->samples[i];
    }

    return modWave
}

sound* filter(sound* s, float fir[], int c) {
    int i;
    int j;
    float sum;

    sound *filterWave = malloc(sizeof(sound));

    filterWave->length = s->length;
    filterWave->rate = s->rate;
    filterWave->samples = malloc(filterWave->length * sizeof(float));

    for (i = 0; i < filterWave->length; i++) {
        sum = 0;

        for (j = 0; j < c; j++) {
            sum += s[i-j] * fir[j];
        }

        filterWave->samples[i] = sum;
    }

    return filterWave;
}

sound* reverb(sound *s, float delay, float attenuation) {
    if (delay < 0.1 && delay > 0 && attenuation > 0 && attenuation < 1) {
        int c = delay * s->rate;
        float fir[c];
        int i;

        fir[0] = 1;
        fir[c-1] = attenuation;

        for (i = 1; i < c - 1; i++)
            fir[i] = 0;

        return filter(s, fir, c);
    } else {
        return null;
    }
}

sound* echo(sound *s, float delay, float attenuation) {
    if (delay <= 1 && delay >= 0.1 && attenuation > 0 && attenuation < 1) {
        int c = delay * s->rate;
        int i;

        sound *wave = malloc(sizeof(sound));

        wave->length = s->length;
        wave->rate = s->rate;
        wave->samples = malloc(wave->length * sizeof(float));

        for (i = 0; i < wave->length; i++) {
            wave->samples[i] = s->samples[i];
            if (i - c >= 0)
                wave->samples[i] += s->samples[i-c] * attenuation;
        }

        return wave;
    } else {
        return null;
    }
}
