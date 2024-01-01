#include "gif0.h"
#include "gif1.h"
#include "gif2.h"
#include "gif3.h"
#include "gif4.h"
#include "gif5.h"
#include "gif6.h"
#include "gif7.h"
#include "gif8.h"
#include "gif9.h"
#include "gif10.h"
#include "gif11.h"
#include "gif12.h"
#include "gif13.h"
#include "gif14.h"
#include "gif15.h"
#include "gif16.h"
#include "gif17.h"
#include "gif18.h"
#include "gif19.h"
#include "gif20.h"
#include "gif21.h"
#include "gif22.h"
#include "gif23.h"
#include "gif24.h"
#include "gif25.h"
#include "gif26.h"
#include "gif27.h"
#include "gif28.h"
#include "gif29.h"
#include "gif30.h"
#include "gif31.h"
#include "gif32.h"
#include "gif33.h"
#include "gif34.h"
#include "gif35.h"
#include "gif36.h"
#include "gif37.h"
#include "gif38.h"
#include "gif39.h"
#include "gif40.h"
#include "gif41.h"
#include "gif42.h"

#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define MEMELIMIT 43

// Giant Array of Gifs
unsigned char** gifs[MEMELIMIT] = {
	gif0,
	gif1,
	gif2,
	gif3,
	gif4,
	gif5,
	gif6,
	gif7,
	gif8,
	gif9,
	gif10,
	gif11,
	gif12,
	gif13,
	gif14,
	gif15,
	gif16,
	gif17,
	gif18,
	gif19,
	gif20,
	gif21,
	gif22,
	gif23,
	gif24,
	gif25,
	gif26,
	gif27,
	gif28,
	gif29,
	gif30,
	gif31,
	gif32,
	gif33,
	gif34,
	gif35,
	gif36,
	gif37,
	gif38,
	gif39,
	gif40,
	gif41,
	gif42,
};

unsigned int* gifs_len[MEMELIMIT] = {
	gif0_len,
	gif1_len,
	gif2_len,
	gif3_len,
	gif4_len,
	gif5_len,
	gif6_len,
	gif7_len,
	gif8_len,
	gif9_len,
	gif10_len,
	gif11_len,
	gif12_len,
	gif13_len,
	gif14_len,
	gif15_len,
	gif16_len,
	gif17_len,
	gif18_len,
	gif19_len,
	gif20_len,
	gif21_len,
	gif22_len,
	gif23_len,
	gif24_len,
	gif25_len,
	gif26_len,
	gif27_len,
	gif28_len,
	gif29_len,
	gif30_len,
	gif31_len,
	gif32_len,
	gif33_len,
	gif34_len,
	gif35_len,
	gif36_len,
	gif37_len,
	gif38_len,
	gif39_len,
	gif40_len,
	gif41_len,
	gif42_len,
};

size_t gifs_frames[MEMELIMIT] = {
	sizeof(gif0_len) / sizeof(gif0_len[0]),
	sizeof(gif1_len) / sizeof(gif1_len[0]),
	sizeof(gif2_len) / sizeof(gif2_len[0]),
	sizeof(gif3_len) / sizeof(gif3_len[0]),
	sizeof(gif4_len) / sizeof(gif4_len[0]),
	sizeof(gif5_len) / sizeof(gif5_len[0]),
	sizeof(gif6_len) / sizeof(gif6_len[0]),
	sizeof(gif7_len) / sizeof(gif7_len[0]),
	sizeof(gif8_len) / sizeof(gif8_len[0]),
	sizeof(gif9_len) / sizeof(gif9_len[0]),
	sizeof(gif10_len) / sizeof(gif10_len[0]),
	sizeof(gif11_len) / sizeof(gif11_len[0]),
	sizeof(gif12_len) / sizeof(gif12_len[0]),
	sizeof(gif13_len) / sizeof(gif13_len[0]),
	sizeof(gif14_len) / sizeof(gif14_len[0]),
	sizeof(gif15_len) / sizeof(gif15_len[0]),
	sizeof(gif16_len) / sizeof(gif16_len[0]),
	sizeof(gif17_len) / sizeof(gif17_len[0]),
	sizeof(gif18_len) / sizeof(gif18_len[0]),
	sizeof(gif19_len) / sizeof(gif19_len[0]),
	sizeof(gif20_len) / sizeof(gif20_len[0]),
	sizeof(gif21_len) / sizeof(gif21_len[0]),
	sizeof(gif22_len) / sizeof(gif22_len[0]),
	sizeof(gif23_len) / sizeof(gif23_len[0]),
	sizeof(gif24_len) / sizeof(gif24_len[0]),
	sizeof(gif25_len) / sizeof(gif25_len[0]),
	sizeof(gif26_len) / sizeof(gif26_len[0]),
	sizeof(gif27_len) / sizeof(gif27_len[0]),
	sizeof(gif28_len) / sizeof(gif28_len[0]),
	sizeof(gif29_len) / sizeof(gif29_len[0]),
	sizeof(gif30_len) / sizeof(gif30_len[0]),
	sizeof(gif31_len) / sizeof(gif31_len[0]),
	sizeof(gif32_len) / sizeof(gif32_len[0]),
	sizeof(gif33_len) / sizeof(gif33_len[0]),
	sizeof(gif34_len) / sizeof(gif34_len[0]),
	sizeof(gif35_len) / sizeof(gif35_len[0]),
	sizeof(gif36_len) / sizeof(gif36_len[0]),
	sizeof(gif37_len) / sizeof(gif37_len[0]),
	sizeof(gif38_len) / sizeof(gif38_len[0]),
	sizeof(gif39_len) / sizeof(gif39_len[0]),
	sizeof(gif40_len) / sizeof(gif40_len[0]),
	sizeof(gif41_len) / sizeof(gif41_len[0]),
	sizeof(gif42_len) / sizeof(gif42_len[0]),
};