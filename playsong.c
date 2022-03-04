#include <stdio.h>

#include "gensnd.h"
#include "sound.h"
#include "process.h"
#include "iosnd.h"

int main() {
    FILE* fp;

    fp = fopen("scale.txt", "r");

    char buff[255];

    fscanf(fp, "%s", buff);

    while (strcmp(buff, "SAMPLERATE")) {
        fscanf(fp, "%s", buff);
    }

    int sampleRate;
    fscanf(fp, "%d", sampleRate);

    fscanf(fp, "%s", buff);

    while (strcmp(buff, "SONG")) {
        printf(buff);
        printf("\n");
        fscanf(fp, "%s", buff);
    }
}
