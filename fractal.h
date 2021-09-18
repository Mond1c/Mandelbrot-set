//
// Created by Mihail Kornilovich on 18.09.2021.
//

#ifndef MANDELBROT_SET_FRACTAL_H
#define MANDELBROT_SET_FRACTAL_H
#include <SDL.h>
#include "complex.h"
#include "settings.h"

class IFractal {
public:
    IFractal() = default;

    virtual void draw(SDL_Renderer* renderer) const = 0;
};

namespace Fractal {
    void drawPoint(SDL_Renderer* renderer, int x, int y, int r, int g, int b);

    class Mandelbrot : public IFractal {
    public:
        Mandelbrot() = default;

        void draw(SDL_Renderer* renderer) const override;
    };

    class Julia : public IFractal {
    public:
        Julia() = default;

        void draw(SDL_Renderer* renderer) const override;
    };
}


#endif //MANDELBROT_SET_FRACTAL_H
