#include "gif0.h"
#include "gif1.h"
#include "gif2.h"

// Giant Array of Gifs
unsigned char** gifs[3] = {
	gif0,
	gif1,
	gif2,
};

unsigned int* gifs_len[3] = {
	gif0_len,
	gif1_len,
	gif2_len,
};
