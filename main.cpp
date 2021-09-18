#include <iostream>
#include <SDL.h>
using namespace std;

const int WIDTH = 800, HEIGHT = 800;
const double x_start = -1.6, x_end = 1.6;
const double y_start = -1.6, y_end = 1.6;

class ComplexNumber {
public:
    ComplexNumber() = default;
    ComplexNumber(double a, double b) : a(a), b(b) {}

    [[nodiscard]] double Length() const {
        return a * a + b * b;
    }

    ComplexNumber operator+(const ComplexNumber& other) {
        return ComplexNumber(a + other.a, b + other.b);
    }

    ComplexNumber operator*(const ComplexNumber& other) {
        return ComplexNumber(a * other.a - b * other.b, 2 * a * other.b);
    }
private:
    double a{};
    double b{};
};

void drawPoint(SDL_Renderer* renderer, int x, int y, int r, int g, int b) {
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_RenderDrawPoint(renderer, x, y);
}

void draw(SDL_Renderer* renderer, int zoom, int x_position, int y_position) {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            ComplexNumber z;
            int i = 0;
            while (i < 100 && z.Length() < 4) {
                z = z * z + ComplexNumber((x - 600) / 180.0, (y - 400) / 180.0);
                ++i;
            }
            double r = 0.1 + i * 0.03 * 0.2;
            double g = 0.2 + i * 0.03 * 0.3;
            double b = 0.3 + i * 0.03 * 0.1;
            drawPoint(renderer, x, y, r * 100, g * 100, b * 100);
        }
    }
    SDL_RenderPresent(renderer);
}

int main() {
    SDL_Window* window = SDL_CreateWindow("Mandelbrot set", SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    int zoom = 1;
    draw(renderer, zoom, WIDTH / 2, HEIGHT / 2);
    while (true) {
        SDL_Event event;
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) break;
        }
    }
    return 0;
}
