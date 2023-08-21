#include "main.h"

SDL_DisplayMode screen;

typedef struct {
	int x, y, w, h, timer, delay, frames;
	float vx, vy, speed;
	unsigned char** gif;
	unsigned int* gif_len;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* texture;
} GifWindow;
// unsigned int tracklist[44];
unsigned int memes = 0;
unsigned int memeLimit = 44;
GifWindow meme[44];

void spawnMeme() {
	meme[memes].x = 0;
	meme[memes].y = 0;
	meme[memes].speed = rand() % 15 + 5;
	meme[memes].vx = meme[memes].speed;
	meme[memes].vy = meme[memes].speed;
	meme[memes].w = rand() % 256 + 256;
	meme[memes].h = rand() % 256 + 256;
	meme[memes].timer = 0;
	meme[memes].delay = rand() % 100;
	meme[memes].frames = 14;
	meme[memes].gif = gifs[memes];
	meme[memes].gif_len = gifs_len[memes];
	meme[memes].window = SDL_CreateWindow("amogus", meme[memes].x, meme[memes].y, meme[memes].w, meme[memes].h, SDL_WINDOW_BORDERLESS);
	meme[memes].renderer = SDL_CreateRenderer(meme[memes].window, -1, SDL_RENDERER_PRESENTVSYNC);
	meme[memes].texture = IMG_LoadTexture_RW(meme[memes].renderer, SDL_RWFromConstMem(meme[memes].gif[0], meme[memes].gif_len[0]), 1);
	memes++;
}

void renderMeme(int i) {
	if (meme[i].x < 0) {
		meme[i].vx = meme[i].speed;
	}
	else if (meme[i].x > screen.w - meme[i].w) {
		meme[i].vx = -meme[i].speed;
	}
	if (meme[i].y < 0) {
		meme[i].vy = meme[i].speed;
	}
	else if (meme[i].y > screen.h - meme[i].h) {
		meme[i].vy = -meme[i].speed;
	}
	meme[i].x += meme[i].vx;
	meme[i].y += meme[i].vy;
	SDL_SetWindowPosition(meme[i].window, meme[i].x, meme[i].y);

	meme[i].timer = SDL_GetTicks() / meme[i].delay % 14;
	meme[i].texture = IMG_LoadTexture_RW(meme[i].renderer, SDL_RWFromConstMem(meme[i].gif[meme[i].timer], meme[i].gif_len[meme[i].timer]), 1);
	
	SDL_RenderClear(meme[i].renderer);
	SDL_RenderCopy(meme[i].renderer, meme[i].texture, NULL, NULL);
	SDL_RenderPresent(meme[i].renderer);	
}

void shuffle(int *array, size_t n) {
	if (n > 1) {
		size_t i;
		for (i = 0; i < n - 1; i++) {
		  size_t j = i + rand() / (43 / (n - i) + 1);
		  int t = array[j];
		  array[j] = array[i];
		  array[i] = t;
		}
	}
}

int main() {

	// Init SDL and Set Random Seed
	SDL_Init(SDL_INIT_VIDEO);
	srand(time(NULL));

	// Shuffle the Order of Memes
	// for (int i = 0; i < 44; i++) {
	// 	tracklist[i] = i;
	// }
	// shuffle(tracklist, 44);

	// Main Loop
	bool quit = false;
	while (!quit) {
		SDL_GetCurrentDisplayMode(0, &screen);
		SDL_Event e; while (SDL_PollEvent(&e)) { if(e.type == SDL_QUIT) quit = true; }

		// Spawn a Window/Meme every 2 seconds
		unsigned int ticks = SDL_GetTicks() / 2000;
		if (ticks != memes && memes < memeLimit) {
			spawnMeme();
		}

		// Render and play the gifs in each Window
		for (int i = 0; i < memes; i++) {
			renderMeme(i);
		}
	}

	return 0;
}
