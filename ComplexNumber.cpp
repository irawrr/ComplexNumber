#include <iostream>
#include "ComplexNumber.h"

template <typename T>
Complex<T>::Complex(T real, T imaginary) : real(real), imaginary(imaginary) {}

template <typename T>
T Complex<T>::getReal() const {
    return real;
}

template <typename T>
void Complex<T>::setReal(T value) {
    real = value;
}

template <typename T>
T Complex<T>::getImaginary() const {
    return imaginary;
}

template <typename T>
void Complex<T>::setImaginary(T value) {
    imaginary = value;
}

template <typename T>
Complex<T> Complex<T>::operator+(const Complex<T>& other) const {
    return Complex<T>(real + other.real, imaginary + other.imaginary);
}

template <typename T>
Complex<T> Complex<T>::operator-(const Complex<T>& other) const {
    return Complex<T>(real - other.real, imaginary - other.imaginary);
}

template <typename T>
Complex<T> Complex<T>::operator*(const Complex<T>& other) const {
    return Complex<T>(real * other.real - imaginary * other.imaginary,
                      real * other.imaginary + imaginary * other.real);
}

template <typename T>
Complex<T> Complex<T>::operator/(const Complex<T>& other) const {
    T denominator = other.real * other.real + other.imaginary * other.imaginary;
    T eps = static_cast<T>(1e-5);
    if (std::fabs(denominator) < eps) {
        throw std::overflow_error("Divide by zero exception");
    }
    return Complex<T>((real * other.real + imaginary * other.imaginary) / denominator,
                      (other.real * imaginary - real * other.imaginary) / denominator);
}


template <typename T>
bool Complex<T>::operator==(const Complex<T>& other) const {
    return (real == other.real) && (imaginary == other.imaginary);
}

template <typename T>
bool Complex<T>::operator==(T value) const {
    return (real == value) && (imaginary == 0);
}

template <typename T>
T Complex<T>::modulus() const {
    return std::sqrt(real * real + imaginary * imaginary);
}

template <typename T>
Complex<T> Complex<T>::power(int exponent) const {
    T mod = modulus();
    T arg = std::atan2(imaginary, real);
    T newMod = std::pow(mod, exponent);
    T newArg = arg * exponent;
    T newReal = newMod * std::cos(newArg);
    T newImaginary = newMod * std::sin(newArg);
    return Complex<T>(newReal, newImaginary);
}

template <typename T>
template <typename U>
Complex<T>::operator U() const {
    return static_cast<U>(real);
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Complex<T>& num) {
    if (num.imaginary < 0) {
        out << num.real << num.imaginary << "i\n";
    } else {
        out << num.real << "+" << num.imaginary << "i\n";
    }
    return out;
}

template class Complex<double>;
template class Complex<float>;
template class Complex<int>;
}