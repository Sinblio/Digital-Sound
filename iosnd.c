#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "iosnd.h"
#include "sound.h"

/*
* outputSound
* when given a sound and a file will check to see if the file is a null pointer in which case it will print to stdin otherwise will print to the file
*
* sound s - sound struct to output
* FILE f - the file to output to
*/
int outputSound(sound* s, FILE *f) {
    //Variable declarations
    int i;

    //checks to see if a file exsits
    if (f == NULL) {
        //outputs to console if file is NULL
        for (i = 0; i < s->length; i ++) {
            printf("%0.6f\n", s->samples[i]);
        }
    } else {
        //otherwise outputs to the file
        for (i = 0; i < s->length; i ++) {
            fprintf(f, "%0.6f\n", s->samples[i]);
        }
    }

    //frees the memory allocated for the sound
    free(s);

    return 0;
}
