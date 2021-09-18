#include <iostream>
#include <SDL.h>

#include "fractal.h"
using namespace std;

int main() {
    SDL_Window* window = SDL_CreateWindow("Mandelbrot set", SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    Fractal::Julia julia;
    julia.draw(renderer);

    while (true) {
        SDL_Event event;
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) break;
        }
    }
    return 0;
}
