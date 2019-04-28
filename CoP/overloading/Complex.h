#pragma once
#include <ostream>
using namespace std;

class Complex
{
private:
    double real;
    double imaginary;

public:
    Complex();
    Complex(double real, double imginary);
    Complex(const Complex& other);
    ~Complex();

    const Complex& operator=(const Complex& other);

    double getReal() const { return real; }
    double getImaginary() const { return imaginary;  }
};

ostream& operator<<(ostream& out, const Complex& c);

Complex operator+(const Complex &c1, const Complex &c2);

Complex operator+(const Complex& c1, double d);
Complex operator+(double d, const Complex& c1);