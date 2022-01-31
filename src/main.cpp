//includes
#include <switch.h>
#include <random>
#include <algorithm>
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
const int tspace = 999;
const int tat = 666;

//different states
const int SPLASH = 0;
const int CODE_SCENE = 1;
const int BUG_SCENE = 2;
const int SCROLL_SPEED = 2;
const int LOGO_SPEED = 3;
int state = CODE_SCENE; //starting state

const int NUM_DOTS = 255;

Mix_Chunk *musique = NULL;
Mix_Music *bg;
const int FONT_WIDTH = 16;
const int FONT_HEIGHT = 16;
SDL_Rect charRect[3][26];

struct dot
{
	int speed;
	float vx, vy;
	float x,y;
};

struct dot demo_dots[NUM_DOTS];

void renderFont(SDL_Texture *tex, SDL_Renderer *ren, const SDL_Rect *sourceRect, int x, int y, int w, int h) {

	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	dest.w = w;
	dest.h = h;

	SDL_RenderCopy(ren, tex, sourceRect, &dest);

}

void renderString(SDL_Texture *tex, SDL_Renderer *ren, string text, int x, int y){
	int col;
	int row;
		for(int i; i< text.length(); i++){
			switch(text[i]){
				case 'A':
				  row = 0;
				  col = 0;
				  break;
				case 'B':
				  row = 0;
				  col = 1;
				  break;
				case 'C':
				  row = 0;
				  col = 2;
				  break;
				case 'D':
				  row = 0;
				  col = 3;
				  break;
				case 'E':
				  row = 0;
				  col = 4;
				  break;
				case 'F':
				  row = 0;
				  col = 5;
				  break;
				case 'G':
				  row = 0;
				  col = 6;
				  break;
				case 'H':
				  row = 0;
				  col = 7;
				  break;
				case 'I':
				  row = 0;
				  col = 8;
				  break;
				case 'J':
				  row = 0;
				  col = 9;
				  break;
				case 'K':
				  row = 0;
				  col = 10;
				  break;
				case 'L':
				  row = 0;
				  col = 11;
				  break;
				case 'M':
				  row = 0;
				  col = 12;
				  break;
				case 'N':
				  row = 0;
				  col = 13;
				  break;
				case 'O':
				  row = 0;
				  col = 14;
				  break;
				case 'P':
				  row = 0;
				  col = 15;
				  break;
				case 'Q':
				  row = 0;
				  col = 16;
				  break;
				case 'R':
				  row = 0;
				  col = 17;
				  break;
				case 'S':
				  row = 0;
				  col = 18;
				  break;
				case 'T':
				  row = 0;
				  col = 19;
				  break;
				case 'U':
				  row = 0;
				  col = 20;
				  break;
				case 'V':
				  row = 0;
				  col = 21;
				  break;
				case 'W':
				  row = 0;
				  col = 22;
				  break;
				case 'X':
				  row = 0;
				  col = 23;
				  break;
				case 'Y':
				  row = 0;
				  col = 24;
				  break;
				case 'Z':
				  row = 0;
				  col = 25;
				  break;
				case 'a':
				  row = 1;
				  col = 0;
				  break;
				case 'b':
				  row = 1;
				  col = 1;
				  break;
				case 'c':
				  row = 1;
				  col = 2;
				  break;
				case 'd':
				  row = 1;
				  col = 3;
				  break;
				case 'e':
				  row = 1;
				  col = 4;
				  break;
				case 'f':
				  row = 1;
				  col = 5;
				  break;
				case 'g':
				  row = 1;
				  col = 6;
				  break;
				case 'h':
				  row = 1;
				  col = 7;
				  break;
				case 'i':
				  row = 1;
				  col = 8;
				  break;
				case 'j':
				  row = 1;
				  col = 9;
				  break;
				case 'k':
				  row = 1;
				  col = 10;
				  break;
				case 'l':
				  row = 1;
				  col = 11;
				  break;
				case 'm':
				  row = 1;
				  col = 12;
				  break;
				case 'n':
				  row = 1;
				  col = 13;
				  break;
				case 'o':
				  row = 1;
				  col = 14;
				  break;
				case 'p':
				  row = 1;
				  col = 15;
				  break;
				case 'q':
				  row = 1;
				  col = 16;
				  break;
				case 'r':
				  row = 1;
				  col = 17;
				  break;
				case 's':
				  row = 1;
				  col = 18;
				  break;
				case 't':
				  row = 1;
				  col = 19;
				  break;
				case 'u':
				  row = 1;
				  col = 20;
				  break;
				case 'v':
				  row = 1;
				  col = 21;
				  break;
				case 'w':
				  row = 1;
				  col = 22;
				  break;
				case 'x':
				  row = 1;
				  col = 23;
				  break;
				case 'y':
				  row = 1;
				  col = 24;
				  break;
				case 'z':
				  row = 1;
				  col = 25;
				  break;
				case ' ':
					row = 2;
					col = 25;
					break;
				case '-':
					row = 2;
					col = 7;
					break;
				case '1':
					row = 2;
					col = 16;
					break;
				case '2':
					row = 2;
					col = 17;
					break;
				case '3':
					row = 2;
					col = 18;
					break;
				case '4':
					row = 2;
					col = 19;
					break;
				case '5':
					row = 2;
					col = 20;
					break;
				case '6':
					row = 2;
					col = 21;
					break;
				case '7':
					row = 2;
					col = 22;
					break;
				case '8':
					row = 2;
					col = 23;
					break;
				case '9':
					row = 2;
					col = 24;
					break;
				case '0':
					row = 2;
					col = 15;
					break;
				case '@':
					row = 2;
					col = 5;
					break;
				case '.':
					row =2;
					col = 13;
					break;
				}
				renderFont(tex, ren, &charRect[row][col], x+(i*FONT_WIDTH), y,FONT_WIDTH,FONT_HEIGHT);
		}
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
float clip(float n, float lower, float upper) {
  return std::max(lower, std::min(n, upper));
}
float zoomRatioCalc(int xPos){
	return (sin(float(xPos)/926.0*3.14))+0.5;
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

void move_dots() {
	int i = 0;
	for (i; i < NUM_DOTS; i ++) {
		demo_dots[i].x = ((int)(demo_dots[i].x + demo_dots[i].speed) % 1280);
	}
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
	int hello_text[20] = {alpha_h, alpha_e,alpha_l,alpha_l,alpha_o,tspace,alpha_f,alpha_r,alpha_i,alpha_e,alpha_n,alpha_d,alpha_s,tspace,alpha_o,alpha_f,tspace,alpha_v,alpha_i,alpha_p};
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024); //init audio mixer
	uint prevTime = SDL_GetTicks(); // Get ticks
	bool quit = false; // quit variable. if true quits and exits application
	bool paused = false; //if the game is paused or not
	int frames = 0; // frames
	float fps; //fps
	int splashTimer = 0; //splash screen timer
	int mainMenuIndex = 0; //main menu image index
	int trPos = 1;
	int scrollPos = 1300;
	float zoomPerc = 1;
	bool zInc = true;
	int lPosX = -500;
	int lPosY = 180;
	bool lFront = true;
	bool bFront = true;
	bool bGoAlgo =false;
 	SDL_Rect bugRect;
	bugRect.x = 10;
	bugRect.y = 10;
	bugRect.w = 1260;
	bugRect.h = 150;
	string topText = "Well hello VIP mGGk here for another shitty release but this time on Nintendo Switch - first greetz to Switchbrew Team for the DevKitPro - Code by mGGk - Music by Zac";
	topText+=" Greetz to friends Popsy Team - Unity - LNX - tmp - AAA - swyng - MJJ PROD - XMEN -- Greetz to legends Razor1911 - Cocoon - TRSI - TBL - Attention Whore";

    //Setup window
    SDL_Window* window = SDL_CreateWindow(nullptr, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 0, 0, SDL_WINDOW_FULLSCREEN);

	//Setup renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	//Load Images
	SDL_Surface* font16X16 = IMG_Load("assets/font/font_16x16.png");
	SDL_Texture* fontTexture = SDL_CreateTextureFromSurface(renderer, font16X16);
	SDL_Surface* font16X16r = IMG_Load("assets/font/font_16x16r.png");
	SDL_Texture* fontTexturer = SDL_CreateTextureFromSurface(renderer, font16X16r);
	SDL_Surface* sLogo = IMG_Load("assets/image/logo-2018.png");
	SDL_Texture* tLogo = SDL_CreateTextureFromSurface(renderer,sLogo);

	//Generateur de dots
	int i = 0;
	for (i;i < NUM_DOTS; i++) {
	  demo_dots[i].x = rand() % SCREEN_WIDTH;
	  demo_dots[i].y = (rand()%(670-50))+50;
	  demo_dots[i].speed = 1 + rand() % 5;
	}
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
		splashTimer++;
		if(state == CODE_SCENE){
			SDL_RenderClear(renderer); //clear the renderer
			//REndu text
			drawLine(renderer, 0, 50, 1280, 50,255,255,255,255);
			renderString(fontTexture,renderer,"mGGk@VIP2k18",10,689);
			drawLine(renderer, 0, 670, 1280, 670,255,255,255,255);
			renderString(fontTexture,renderer,topText,scrollPos,10);
			scrollPos-=SCROLL_SPEED;
			if(scrollPos < -5000){
				scrollPos = 1300;
			}
			//REndu starfield
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			for (int x=0; x<NUM_DOTS; x++) {
				SDL_RenderDrawPoint(renderer, demo_dots[x].x, demo_dots[x].y);
			}
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
			//Rendu item
			if(splashTimer > 1450){
					renderTexture(tLogo,renderer,lPosX,lPosY,sLogo->w,sLogo->h);
					//renderString(fontTexture, renderer, to_string(splashTimer),10,100);
					//Gestion sens
					if(bGoAlgo ==true){
						if(bFront){
								lPosX+=LOGO_SPEED;
						}else{
								lPosX-=LOGO_SPEED;
						}
						if(lPosX>926){
							bFront = false;
						}
						if(lPosX < 0){
							bFront = true;
						}
					}else{
							lPosX+=LOGO_SPEED;
					}
					if(lPosX>1){
						bGoAlgo = true;
					}

			}
			move_dots();

			//Flip surface
			SDL_RenderPresent(renderer); //show renderer on screen
			if(splashTimer > 4000){
				state = BUG_SCENE;
			}
		}

		if(state == BUG_SCENE){
				Mix_HaltMusic();
				SDL_RenderClear(renderer);
				SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
				SDL_RenderDrawRect(renderer,&bugRect);
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
				renderString(fontTexturer, renderer, "Software Failure. Throw your switch to continue", 264, 60);
				renderString(fontTexturer, renderer, "Guru Meditation @42666.NOMOREBEERINTHEFRIDGE", 288, 80);
				renderString(fontTexturer, renderer, "And also burn your ARM processors and go back to the 68k", 192, 100);
				SDL_RenderPresent(renderer);
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
