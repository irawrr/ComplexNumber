#include <iostream>
#include <cmath>

class Complex
{
private:
    double real;
    double imaginary;

public:
    Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}

    double getReal() const { return real; }
    void setReal(double real) { this->real = real; }

    double getImaginary() const { return imaginary; }
    void setImaginary(double imaginary) { this->imaginary = imaginary; }

    Complex operator+(const Complex& other) const
    {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    Complex operator-(const Complex& other) const
    {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    Complex operator*(const Complex& other) const
    {
        double newReal = real * other.real - imaginary * other.imaginary;
        double newImaginary = real * other.imaginary + imaginary * other.real;
        return Complex(newReal, newImaginary);
    }

    Complex operator/(const Complex& other) const
    {
        double denominator = other.real * other.real + other.imaginary * other.imaginary;
        double newReal = (real * other.real + imaginary * other.imaginary) / denominator;
        double newImaginary = (imaginary * other.real - real * other.imaginary) / denominator;
        return Complex(newReal, newImaginary);
    }

    bool operator==(const Complex& other) const
    {
        return (real == other.real) && (imaginary == other.imaginary);
    }

    bool operator!=(const Complex& other) const
    {
        return !(*this == other);
    }

    bool operator==(const double& number) const
    {
        return (real == number) && (imaginary == 0);
    }

    bool operator!=(const double& number) const
    {
        return !(*this == number);
    }

    double modulus() const
    {
        return sqrt(real * real + imaginary * imaginary);
    }

    Complex power(int exponent) const
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
};

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
