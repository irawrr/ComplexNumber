#pragma once
#include <iostream>

template <typename T>
class Complex
{
private:
    T real;
    T imaginary;

public:
    Complex(T real, T imaginary);

    T getReal() const;
    void setReal(T value);
    T getImaginary() const;
    void setImaginary(T value);

    Complex<T> operator+(const Complex<T>& other) const;
    Complex<T> operator-(const Complex<T>& other) const;
    Complex<T> operator*(const Complex<T>& other) const;
    Complex<T> operator/(const Complex<T>& other) const;

    bool operator==(const Complex<T>& other) const;
    bool operator==(T value) const;

    T modulus() const;
    Complex<T> power(int exponent) const;

    friend std::ostream& operator<<(std::ostream& out, const Complex<T>& num);

    template <typename U>
    explicit operator U() const;
};

using ComplexDouble = Complex<double>;
using ComplexFloat = Complex<float>;
using ComplexInt = Complex<int>;
