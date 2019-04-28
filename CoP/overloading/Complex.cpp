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


Complex operator+(const Complex& c1, const Complex& c2) {
    return Complex(c1.getReal() + c2.getReal(), c1.getImaginary() + c2.getImaginary());
}

Complex operator+(const Complex& c1, double d) {
    return Complex(c1.getReal() + d, c1.getImaginary());
}

Complex operator+(double d, const Complex& c1) {
    return Complex(c1.getReal() + d, c1.getImaginary());
}

bool Complex::operator== (const Complex &other) const {
    return (real == other.real) && (imaginary == other.imaginary);
}

// opposite of == operator; just reuse == with a not
bool Complex::operator!= (const Complex& other) const {
    return !(*this == other);
}

Complex Complex::operator*() const {
    return Complex(real, -imaginary);
}