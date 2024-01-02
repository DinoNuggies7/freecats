#include "gifdata.h" // change to testdata.h for debugging, it only includes 3 gifs

SDL_DisplayMode screen;

typedef struct {
	int x, y, w, h, timer, delay, frames;
	double vx, vy, speed;
	unsigned char** gif;
	unsigned int* gif_len;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* texture;
} GifWindow;
int memes = 0;
int tracklist[MEMELIMIT];
GifWindow meme[MEMELIMIT];

bool collideMeme(int i, int j) {
	if (meme[i].x < meme[j].x + meme[j].w
	 && meme[i].x + meme[i].w > meme[j].x
	 && meme[i].y < meme[j].y + meme[j].h
	 && meme[i].y + meme[i].h > meme[j].y) {
		return true;
	}
	return false;
}

void spawnMeme() {
	meme[memes].speed = rand() % 5 + 5;
	meme[memes].vx = meme[memes].speed;
	meme[memes].vy = meme[memes].speed;
	meme[memes].w = rand() % 300 + 100;
	meme[memes].h = rand() % 300 + 100;
	meme[memes].x = rand() % (screen.w - meme[memes].w);
	meme[memes].y = rand() % (screen.h - meme[memes].h);
	meme[memes].timer = 0;
	meme[memes].delay = 100;
	meme[memes].frames = (int)gifs_frames[tracklist[memes]];
	meme[memes].gif = gifs[tracklist[memes]];
	meme[memes].gif_len = gifs_len[tracklist[memes]];
	meme[memes].window = SDL_CreateWindow("kitty cat >>>:3", meme[memes].x, meme[memes].y, meme[memes].w, meme[memes].h, SDL_WINDOW_BORDERLESS | SDL_WINDOW_ALWAYS_ON_TOP);
	meme[memes].renderer = SDL_CreateRenderer(meme[memes].window, -1, SDL_RENDERER_PRESENTVSYNC);
	meme[memes].texture = IMG_LoadTexture_RW(meme[memes].renderer, SDL_RWFromConstMem(meme[memes].gif[0], meme[memes].gif_len[0]), 1);
	memes++;
}

void renderMeme(int i) {
	for (int j = 0; j < memes; j++) {
		if (meme[i].x <= 0)
			meme[i].vx = meme[i].speed;
		else if (meme[i].x >= screen.w - meme[i].w)
			meme[i].vx = -meme[i].speed;
		if (meme[i].y <= 0)
			meme[i].vy = meme[i].speed;
		else if (meme[i].y >= screen.h - meme[i].h)
			meme[i].vy = -meme[i].speed;
	}
	meme[i].x += meme[i].vx;
	meme[i].y += meme[i].vy;
	SDL_SetWindowPosition(meme[i].window, meme[i].x, meme[i].y);

	meme[i].timer = SDL_GetTicks() / meme[i].delay % meme[i].frames;
	SDL_DestroyTexture(meme[i].texture);
	meme[i].texture = IMG_LoadTexture_RW(meme[i].renderer, SDL_RWFromConstMem(meme[i].gif[meme[i].timer], meme[i].gif_len[meme[i].timer]), 1);
	
	SDL_RenderClear(meme[i].renderer);
	SDL_RenderCopy(meme[i].renderer, meme[i].texture, NULL, NULL);
	SDL_RenderPresent(meme[i].renderer);
}

int main(int argc, char** argv) {
	// Init SDL and Set Random Seed
	SDL_Init(SDL_INIT_VIDEO);
	srand(time(NULL));

	// Shuffle the Order of Memes
	for (int i = 0; i < MEMELIMIT; i++) {
		tracklist[i] = i;
	}

	if (MEMELIMIT > 1) {
		int _tmp[MEMELIMIT];
		for (int i = 0; i < MEMELIMIT; i++) {
			int _rand = rand() % MEMELIMIT;
			for (int j = 0; j < i; j++) {
				while (_rand == _tmp[j]) {
					_rand = rand() % MEMELIMIT;
					j = 0;
				}
			}
			tracklist[i] = _rand;
			_tmp[i] = _rand;
		}
	}

	// Main Loop
	// SDL_Event event;
	bool quit = false;
	while (!quit) {
		SDL_GetCurrentDisplayMode(0, &screen);
		// while (SDL_PollEvent(&event)) { // Comment for release, so you can't close it
		// 	if (event.type == SDL_QUIT || event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
		// 		quit = true;
		// }

		// Spawn a Window/Meme every 10 seconds
		unsigned long ticks = SDL_GetTicks() / 10000;
		if (ticks >= memes && memes < MEMELIMIT) {
			spawnMeme();
		}

		// Render and play the gifs in each Window
		for (int i = 0; i < memes; i++) {
			renderMeme(i);
		}
	}

	for (int i = 0; i < MEMELIMIT; i++) {
		SDL_DestroyWindow(meme[i].window);
		SDL_DestroyRenderer(meme[i].renderer);
		SDL_DestroyTexture(meme[i].texture);
	}

	SDL_Quit();
	return 0;
}

int WinMain(int argc, char** argv) {
	return main(argc, argv);
}