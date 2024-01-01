#include "gif0.h"
#include "gif1.h"
#include "gif2.h"

#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define MEMELIMIT 3

// Giant Array of Gifs
unsigned char** gifs[MEMELIMIT] = {
	gif0,
	gif1,
	gif2,
};

unsigned int* gifs_len[MEMELIMIT] = {
	gif0_len,
	gif1_len,
	gif2_len,
};

size_t gifs_frames[MEMELIMIT] = {
	sizeof(gif0_len) / sizeof(gif0_len[0]),
	sizeof(gif1_len) / sizeof(gif1_len[0]),
	sizeof(gif2_len) / sizeof(gif2_len[0]),
};