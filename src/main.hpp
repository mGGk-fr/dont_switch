#ifndef MAIN_HPP_
#define MAIN_HPP_

#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

void Initialize(SDL_Renderer **ren, SDL_Window **win);
void Cleanup(SDL_Renderer **ren, SDL_Window **win);

#endif /* MAIN_HPP_ */