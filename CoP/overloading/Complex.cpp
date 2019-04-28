#include "Complex.h"
#include <iostream>

Complex::Complex() : real(0), imaginary(0)
{
}

Complex::Complex(double real, double imaginary) : real(real), imaginary(imaginary)
{
}

Complex::Complex(const Complex& other) {
    cout << "copy constructor" << endl;
    real = other.real;
    imaginary = other.imaginary;
}

Complex::~Complex()
{
}

const Complex& Complex::operator=(const Complex& other) {
    real = other.real;
    imaginary = other.imaginary;

    return *this;
}

// overload using getter functions instead of using friend 
// getReal and getImaginary needs to be const in order to be called
ostream& operator<<(ostream& out, const Complex& c) {
    return out << "(" << c.getReal() << "," << c.getImaginary() << ")";
}
