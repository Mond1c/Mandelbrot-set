//
// Created by Mihail Kornilovich on 18.09.2021.
//

#include "fractal.h"

void Fractal::drawPoint(SDL_Renderer* renderer, int x, int y, int r, int g, int b) {
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_RenderDrawPoint(renderer, x, y);
}

void Fractal::Mandelbrot::draw(SDL_Renderer *renderer) const {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            Complex z;
            int i = 0;
            while (i < 100 && z.Length() < 4) {
                z = z * z + Complex((x - WIDTH / 4 * 3) / 180.0, (y - HEIGHT / 2) / 180.0);
                ++i;
            }
            double r = 0.1 + i * 0.03 * 0.2;
            double g = 0.2 + i * 0.03 * 0.3;
            double b = 0.3 + i * 0.03 * 0.1;
            Fractal::drawPoint(renderer, x, y, r * 100, g * 100, b * 100);
        }
    }
    SDL_RenderPresent(renderer);
}

void Fractal::Julia::draw(SDL_Renderer *renderer) const {
    Complex c(-0.70176, -0.3842);
    Complex next, prev;

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            next = Complex(1.5 * (x - WIDTH / 2) / (0.5 * WIDTH), (y - HEIGHT / 2) / (0.5 * HEIGHT));
            int i;
            for (i = 0; i < 100; ++i) {
                prev = next;
                next = Complex(prev.getA() * prev.getA() - prev.getB() * prev.getB() + c.getA(),
                               2 * prev.getA() * prev.getB() + c.getB());
                if ((next.Length() > 4)) break;
            }
            int r = (i * 9) % 255;
            int g = 0;
            int b = (i * 9) % 255;
            drawPoint(renderer, x, y, r, g, b);
        }
    }
    SDL_RenderPresent(renderer);
}
