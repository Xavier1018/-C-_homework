#include<iostream>
using namespace std;

class Complex
{
public:
    static const Complex i; // Declaration of the constant i
    Complex(double real = 0, double imaginary = 0) : real(real), imaginary(imaginary) {} // Parameterized constructor

    // Overloaded operators
    bool operator==(const Complex& other) const { return (real == other.real) && (imaginary == other.imaginary); } // Equality operator
    friend Complex operator+(const Complex& a, const Complex& b); // Addition operator declaration
    friend Complex operator-(const Complex& a, const Complex& b); // Subtraction operator declaration
    friend Complex operator*(const Complex& a, const Complex& b); // Multiplication operator declaration

    // Friend functions for input and output operators
    friend istream& operator>>(istream& in, Complex& complex); // Input operator declaration
    friend ostream& operator<<(ostream& out, const Complex& complex); // Output operator declaration

private:
    double real; // Real part of the complex number
    double imaginary; // Imaginary part of the complex number
};

// Definition of the constant i
const Complex Complex::i(0, 1);

// Definition of the multiplication operator
Complex operator*(const Complex& a, const Complex& b) {
    double result_real = a.real * b.real - a.imaginary * b.imaginary;
    double result_imaginary = a.real * b.imaginary + a.imaginary * b.real;
    return Complex(result_real, result_imaginary);
}

// Addition operator definition
Complex operator+(const Complex& a, const Complex& b) {
    return Complex(a.real + b.real, a.imaginary + b.imaginary);
}

// Subtraction operator definition
Complex operator-(const Complex& a, const Complex& b) {
    return Complex(a.real - b.real, a.imaginary - b.imaginary);
}

// Input operator definition
istream& operator>>(istream& in, Complex& complex) {
    cout << "Enter the real part: ";
    in >> complex.real;
    cout << "Enter the imaginary part: ";
    in >> complex.imaginary;
    return in;
}

// Output operator definition
ostream& operator<<(ostream& out, const Complex& complex) {
    return out << complex.real << " + " << complex.imaginary << "i";
}

int main()
{
    Complex a, b;
    cout << "Enter the first complex number:" << endl;
    cin >> a;
    cout << "Enter the second complex number:" << endl;
    cin >> b;

    Complex c = a + b;
    Complex d = a - b;
    Complex e = a * b;

    // Output test results
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a + b = " << c << endl;
    cout << "a - b = " << d << endl;
    cout << "a * b = " << e << endl;

    return 0;
}

