//includes
#include <switch.h>
#include <random>
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <math.h>
#include <stdio.h>
#include "main.hpp"

using namespace std;

const int upper = 0;
const int lower = 1;
const int symbol = 2;


const int alpha_a = 0;
const int alpha_b = 1;
const int alpha_c = 2;
const int alpha_d = 3;
const int alpha_e = 4;
const int alpha_f = 5;
const int alpha_g = 6;
const int alpha_h = 7;
const int alpha_i = 8;
const int alpha_j = 9;
const int alpha_k = 10;
const int alpha_l = 11;
const int alpha_m = 12;
const int alpha_n = 13;
const int alpha_o = 14;
const int alpha_p = 15;
const int alpha_q = 16;
const int alpha_r = 17;
const int alpha_s = 18;
const int alpha_t = 19;
const int alpha_u = 20;
const int alpha_v = 21;
const int alpha_w = 22;
const int alpha_x = 23;
const int alpha_y = 24;
const int alpha_z = 25;

const int colon = 14;
const int number_0 = 15;
const int number_1 = 16;
const int number_2 = 17;
const int number_3 = 18;
const int number_4 = 19;
const int number_5 = 20;
const int number_6 = 21;
const int number_7 = 22;
const int number_8 = 23;
const int number_9 = 24;
const int space = 25;


//different states
const int SPLASH = 0;
const int CODE_SCENE = 1;
int state = SPLASH; //starting state

Mix_Chunk *musique = NULL;
Mix_Music *bg;
const int FONT_WIDTH = 16;
const int FONT_HEIGHT = 16;

SDL_Rect charRect[3][26];


void renderFont(SDL_Texture *tex, SDL_Renderer *ren, const SDL_Rect *sourceRect, int x, int y, int w, int h) {
	
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	dest.w = w;
	dest.h = h;
	
	SDL_RenderCopy(ren, tex, sourceRect, &dest);
	
}

//function to render a texture to a surface at x, y, w, y
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w=-1, int h=-1) {
	
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	dest.w = w;
	dest.h = h;
	
	if (w == -1 || h == -1) {
		SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h); //if w and h not set get texture w and h
	}

	SDL_RenderCopy(ren, tex, NULL, &dest); // render the texture

}

void PlaySound(Mix_Chunk* sound) { //function to play a sound 
	if (Mix_PlayChannel( -1, sound, 0) == -1) {
		return;
	}
}

void drawLine(SDL_Renderer* renderer, int x, int y, int w, int h, Uint8 r = 0, Uint8 g = 255, Uint8 b = 0, Uint8 a = 255 ) { //funtion to draw a line x, y, w, h, with a rgb color of red, green, blue, alpha
	
	SDL_SetRenderDrawColor(renderer, r, g, b, a); //set the render color to r,g,b,a
	SDL_RenderDrawLine(renderer, x, y, w, h); //draw the line
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0); //set the render color back to transparent
	
}

int main(int argc, char **argv) {
	
	for (int y=0; y<3; y++) {
		for (int x=0; x<26; x++) {
		
		charRect[y][x].x = x * FONT_WIDTH;
		charRect[y][x].y = y * FONT_HEIGHT;
		charRect[y][x].w = FONT_WIDTH;
		charRect[y][x].h = FONT_HEIGHT;
		
	}
}

	SDL_Init(SDL_INIT_EVERYTHING); //init sdl
	IMG_Init(IMG_INIT_JPG); //init image lib
	int hello_text[20] = {alpha_h, alpha_e,alpha_l,alpha_l,alpha_o,space,alpha_f,alpha_r,alpha_i,alpha_e,alpha_n,alpha_d,alpha_s,space,alpha_o,alpha_f,space,alpha_v,alpha_i,alpha_p};
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024); //init audio mixer
	uint prevTime = SDL_GetTicks(); // Get ticks
	bool quit = false; // quit variable. if true quits and exits application
	bool paused = false; //if the game is paused or not
	int frames = 0; // frames
	float fps; //fps
	int splashTimer = 0; //splash screen timer
	int mainMenuIndex = 0; //main menu image index
	
    //Setup window
    SDL_Window* window = SDL_CreateWindow(nullptr, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP);
	
	//Setup renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	
	//Load Images
	SDL_Surface* splashImage = IMG_Load("assets/image/splash.png");
	SDL_Texture* splashTexture = SDL_CreateTextureFromSurface(renderer, splashImage);
	SDL_Surface* font16X16 = IMG_Load("assets/font/font_16x16.png");
	SDL_Texture* fontTexture = SDL_CreateTextureFromSurface(renderer, font16X16);
	
	//convert Images to Textures
	
	bg = Mix_LoadMUS("assets/audio/bg.ogg");
	Mix_VolumeMusic(MIX_MAX_VOLUME);
	Mix_PlayMusic(bg, -1);
	while(appletMainLoop() && !quit) { //main game loop
		++frames; //increase frames counter
		uint currTime = SDL_GetTicks(); //current time since last tick
		float elapsed = (currTime - prevTime); //elapsed time
		
		if (elapsed > 100) { //if elapsed time id greater than 100
			
			fps = round(frames / (elapsed / 1000.0)); //round fps
			frames = 0; //reset frames
			prevTime = currTime; //set previous time to current time
			
		}
		
		//Scan all the inputs. This should be done once for each frame
		hidScanInput();
		
		//if splash 
		if (state == SPLASH) {
			splashTimer ++; //increase splash timer
			
			if (splashTimer >= 50) { //if splash timer is greater than 75
				state = CODE_SCENE; //change state to main menu
			}
			
			SDL_RenderClear(renderer); //clear the renderer
			renderTexture(splashTexture, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT); //render the splash screen
			SDL_RenderPresent(renderer); //show renderer on screen

		}
		if(state == CODE_SCENE){
			SDL_RenderClear(renderer); //clear the renderer
			for (int x=0; x<20; x++) {
				if(x!=space){
					renderFont(fontTexture, renderer, &charRect[upper][hello_text[x]], x * FONT_WIDTH, 0 , FONT_WIDTH, FONT_HEIGHT);
				}else{
					renderFont(fontTexture, renderer, &charRect[symbol][hello_text[x]], x * FONT_WIDTH, 0 , FONT_WIDTH, FONT_HEIGHT);
				}
				
			}
			SDL_RenderPresent(renderer); //show renderer on screen

		}
		
	}
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	
	Mix_FreeChunk(musique);
	Mix_CloseAudio();
	IMG_Quit();
	SDL_Quit();
	return 0;
}