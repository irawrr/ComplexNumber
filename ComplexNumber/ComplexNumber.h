#pragma once
#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
private:
    double real;
    double imaginary;

public:
    Complex(double real, double imaginary);
    double getReal() const;
    void setReal(double real);
    double getImaginary() const;
    void setImaginary(double imaginary);
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;
    bool operator==(const double& number) const;
    bool operator!=(const double& number) const;
    double modulus() const;
    Complex power(int exponent) const;
};

#endif  // COMPLEX_H
