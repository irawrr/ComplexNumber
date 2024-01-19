#pragma once
#include <iostream>

class Complex
{
private:
    double real;
    double imaginary;

public:
    friend std::ostream& operator <<(std::ostream&, const Complex&);
    Complex(double real, double imaginary);
    double getReal() const;
    void setReal(const double value);
    double getImaginary() const;
    void setImaginary(const double value);
    Complex operator+(const Complex& other);
    Complex operator-(const Complex& other);
    Complex operator*(const Complex& other);
    Complex operator/(const Complex& other);
    bool operator==(const Complex& other);
    bool operator==(const double& other);
    double modulus() const;
    Complex power(int exponent) const;
};

std::ostream& operator << (std::ostream& out, const Complex& num);
