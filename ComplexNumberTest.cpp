#include "pch.h"
#include "CppUnitTest.h"
#include "Complex.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ComplexNumberTest
{
    TEST_CLASS(ComplexNumberTest)
    {
    public:
        const double eps = 1e-5;

        TEST_METHOD(SumTest)
        {
            Complex num1(4.13, -3.333);
            Complex num2(-23, 4);
            Complex result = num1 + num2;
            Assert::IsTrue(fabs(-18.87 - result.getReal()) < eps);
            Assert::IsTrue(fabs(0.667 - result.getImaginary()) < eps);
        }

        TEST_METHOD(SubtractionTest)
        {
            Complex num1(4.13, -3.333);
            Complex num2(-23, 4);
            Complex result = num1 - num2;
            Assert::IsTrue(fabs(27.13 - result.getReal()) < eps);
            Assert::IsTrue(fabs(-7.333 - result.getImaginary()) < eps);
        }

        TEST_METHOD(MultiplicationTest)
        {
            Complex num1(2, -3);
            Complex num2(5, 1);
            Complex result = num1 * num2;
            Assert::IsTrue(fabs(13 - result.getReal()) < eps);
            Assert::IsTrue(fabs(7 - result.getImaginary()) < eps);
        }

        TEST_METHOD(DivisionTest)
        {
            Complex num1(3, -2);
            Complex num2(1, 2);
            Complex result = num1 / num2;
            Assert::IsTrue(fabs(0.5 - result.getReal()) < eps);
            Assert::IsTrue(fabs(-2 - result.getImaginary()) < eps);
        }

        TEST_METHOD(PowerTest)
        {
            Complex num(2, 3);
            Complex result = num.power(3);
            Assert::IsTrue(fabs(-46 - result.getReal()) < eps);
            Assert::IsTrue(fabs(9 - result.getImaginary()) < eps);
        }

        TEST_METHOD(ModulusTest)
        {
            Complex num(3, 4);
            Assert::IsTrue(fabs(5 - num.modulus()) < eps);
        }

        TEST_METHOD(EqualityTest)
        {
            Complex num1(3, 5);
            Complex num2(3, 5);
            Assert::IsTrue(num1 == num2);
        }

        TEST_METHOD(CastingTest)
        {
            Complex num(3.14, 2.71);
            int intValue = static_cast<int>(num);
            Assert::AreEqual(3, intValue);

            float floatValue = static_cast<float>(num);
            Assert::AreEqual(3.14f, floatValue, static_cast<float>(eps));
        }

        TEST_METHOD(NegativePowerTest)
        {
            Complex num(2, 3);
            Complex result = num.power(-2);
            Assert::IsTrue(fabs(0.0384615 - result.getReal()) < eps);
            Assert::IsTrue(fabs(-0.0576923 - result.getImaginary()) < eps);
        }

        TEST_METHOD(ZeroPowerTest)
        {
            Complex num(2, 3);
            Complex result = num.power(0);
            Assert::IsTrue(fabs(1 - result.getReal()) < eps);
            Assert::IsTrue(fabs(0 - result.getImaginary()) < eps);
        }

        TEST_METHOD(NegativeModulusTest)
        {
            Complex num(3, -4);
            Assert::IsTrue(fabs(5 - num.modulus()) < eps);
        }

        TEST_METHOD(NonEqualTest)
        {
            Complex num1(3, 5);
            Complex num2(4, 5);
            Assert::IsFalse(num1 == num2);
        }
    };
}
