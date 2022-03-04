#ifndef IOSND_H
#define IOSND_H

//Needed for the FILE passed in outputSound
#include <stdio.h>
#include "sound.h"

int outputSound(sound* s, FILE *f);

#endif
