#include <iostream>
#include "ComplexNumber.h"


Complex::Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}

double Complex::getReal() const { return real; }
void Complex::setReal(const double value) { real = value; }

double Complex::getImaginary() const { return imaginary; }
void Complex::setImaginary(const double value) { imaginary = value; }

Complex::Complex operator+(const Complex& other)
{
    double newReal = real + other.real;
    double newImaginary = imaginary + other.imaginary;
    return Complex(newReal, newImaginary);
}

Complex::Complex operator-(const Complex& other)
{
    double newReal = real - other.real;
    double newImaginary = imaginary - other.imaginary;
    return ComplexNumber(newReal, newImaginary);
}

Complex::Complex operator*(const Complex& other) const
{
    double newReal = real * other.real - imaginary * other.imaginary;
    double newImaginary = real * other.imaginary + imaginary * other.real;
    return Complex(newReal, newImaginary);
}

Complex::Complex operator/(const Complex& other) const
{
    double denominator = other.real * other.real + other.imaginary * other.imaginary;
    double eps = 1e-5;
    if (std::fabs(denominator) < eps)
    {
        throw std::overflow_error("Divide by zero exception");
    }
    double newReal = (real * other.real + imaginary * other.imaginary) / denominator;
    double newImaginary = (other.real * imaginary - real * other.imaginary) / denominator;
    return Complex(newReal, newImaginary);
}

bool Complex::operator==(const Complex& other) const
{
    return (real == other.real) && (imaginary == other.imaginary);
}

bool Complex::operator==(const double& other) const
{
    double eps = 1e-5;
    return (real = other && std::fabs(imaginary) < eps);
}

double Complex::modulus() const
{
    return sqrt(real * real + imaginary * imaginary);
}

Complex::Complex power(int exponent) const
{
    double mod = modulus();
    double arg = atan2(imaginary, real);
    double newMod = pow(mod, exponent);
    double newArg = arg * exponent;
    double newReal = newMod * cos(newArg);
    double newImaginary = newMod * sin(newArg);
    return Complex(newReal, newImaginary);
}

std::ostream& operator<<(std::ostream& out, const Complex& complex)
{
    if (complex.imaginary < 0)
    {
        out << complex.real << complex.imaginary << "i\n";
    }
    else
    {
        out << complex.real << "+" << complex.imaginary << "i\n";
    }
    return out;
}