//
// Created by Mihail Kornilovich on 18.09.2021.
//

#ifndef MANDELBROT_SET_COMPLEX_H
#define MANDELBROT_SET_COMPLEX_H

#endif //MANDELBROT_SET_COMPLEX_H

class Complex {
public:
    Complex() = default;
    Complex(double a, double b) : a(a), b(b) {}

    [[nodiscard]] double Length() const {
        return a * a + b * b;
    }

    Complex operator+(const Complex& other) {
        return Complex(a + other.a, b + other.b);
    }

    Complex operator*(const Complex& other) {
        return Complex(a * other.a - b * other.b, 2 * a * other.b);
    }

    [[nodiscard]] double getA() const {
        return a;
    }

    [[nodiscard]] double getB() const {
        return b;
    }
private:
    double a{};
    double b{};
};