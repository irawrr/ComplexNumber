#include <iostream>
#include "ComplexNumber.h"


Complex::Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}

double Complex::getReal() const { return real; }
void Complex::setReal(double real) { this->real = real; }

double Complex::getImaginary() const { return imaginary; }
void Complex::setImaginary(double imaginary) { this->imaginary = imaginary; }

Complex::Complex operator+(const Complex& other) const
{
    return Complex(real + other.real, imaginary + other.imaginary);
}

Complex::Complex operator-(const Complex& other) const
{
    return Complex(real - other.real, imaginary - other.imaginary);
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
    double newReal = (real * other.real + imaginary * other.imaginary) / denominator;
    double newImaginary = (imaginary * other.real - real * other.imaginary) / denominator;
    return Complex(newReal, newImaginary);
}

bool Complex::operator==(const Complex& other) const
{
    return (real == other.real) && (imaginary == other.imaginary);
}

bool Complex::operator!=(const Complex& other) const
{
    return !(*this == other);
}

bool Complex::operator==(const double& number) const
{
    return (real == number) && (imaginary == 0);
}

bool Complex::operator!=(const double& number) const
{
    return !(*this == number);
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

friend std::ostream& operator<<(std::ostream& os, const Complex& complex)
{
    os << complex.real;
    if (complex.imaginary >= 0)
    {
        os << " + " << complex.imaginary << "i";
    }
    else
    {
        os << " - " << -complex.imaginary << "i";
    }
    return os;
}

int main()
{
    Complex c1(3, 4);
    Complex c2(1, -2);

    Complex sum = c1 + c2;
    Complex difference = c1 - c2;
    Complex product = c1 * c2;
    Complex quotient = c1 / c2;

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << difference << std::endl;
    std::cout << "Product: " << product << std::endl;
    std::cout << "Quotient: " << quotient << std::endl;

    std::cout << "Modulus of c1: " << c1.modulus() << std::endl;
    std::cout << "c1 to the power of 3: " << c1.power(3) << std::endl;
    std::cout << "c1 is equal to c2: " << (c1 == c2) << std::endl;
    std::cout << "c1 is equal to 3: " << (c1 == 3) << std::endl;

    return 0;
}
