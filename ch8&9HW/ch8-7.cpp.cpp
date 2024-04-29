#include <iostream>
using namespace std;

// Declaration of the PrimeNumber class
class PrimeNumber {
public:
    // Constructors
    PrimeNumber() : number(1) {} // Default constructor sets number to 1
    PrimeNumber(int n); // Constructor with parameter

    // Getter function to retrieve the prime number
    int getNumber() const { return number; }

    // Overloaded increment and decrement operators
    PrimeNumber& operator++();  // Prefix increment operator
    PrimeNumber operator++(int);  // Postfix increment operator
    PrimeNumber& operator--();  // Prefix decrement operator
    PrimeNumber operator--(int);  // Postfix decrement operator

private:
    // Private member variables
    int number;
    // Helper function to check if a number is prime
    bool isPrime(int n);
};

// Definition of the PrimeNumber constructor with parameter
PrimeNumber::PrimeNumber(int n) {
    if (isPrime(n)) {
        number = n;
    }
    else {
        cout << " Error: " << n << " is not a prime number." << endl;
        number = 1; // Set to default value if input is not prime
    }
}

// Definition of the helper function to check if a number is prime
bool PrimeNumber::isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

// Definition of the prefix increment operator
PrimeNumber& PrimeNumber::operator++() {
    do {
        number++;
    } while (!isPrime(number)); // Increment until finding the next prime
    return *this; // Return a reference to the modified object
}

// Definition of the postfix increment operator
PrimeNumber PrimeNumber::operator++(int) {
    PrimeNumber temp(*this); // Create a copy of the current object
    ++(*this); // Increment the current object
    return temp; // Return the copy before the increment
}

// Definition of the prefix decrement operator
PrimeNumber& PrimeNumber::operator--() {
    do {
        number--;
    } while (!isPrime(number) && number > 1); // Decrement until finding the previous prime
    if (number == 1) {
        cerr << "Error: No prime number less than 2." << endl;
        number = 2; // Set to default value if no prime number less than 2
    }
    return *this; // Return a reference to the modified object
}

// Definition of the postfix decrement operator
PrimeNumber PrimeNumber::operator--(int) {
    PrimeNumber temp(*this); // Create a copy of the current object
    --(*this); // Decrement the current object
    return temp; // Return the copy before the decrement
}

// Main function to demonstrate the usage of the PrimeNumber class
int main() {
    PrimeNumber prime1; // Create a PrimeNumber object using the default constructor
    PrimeNumber prime2(13); // Create a PrimeNumber object with the value 13

    // Output the initial values of prime1 and prime2
    cout << "Prime1: " << prime1.getNumber() << endl;
    cout << "Prime2: " << prime2.getNumber() << endl;

    // Increment prime1 using the prefix increment operator
    ++prime1;
    cout << "Prime1 after prefix: " << prime1.getNumber() << endl;

    // Increment prime2 using the postfix increment operator
    PrimeNumber prime3 = prime2++;
    cout << "Prime2 after postfix: " << prime2.getNumber() << endl;
    cout << "Prime3 (postfix result): " << prime3.getNumber() << endl;

    // Decrement prime1 using the prefix decrement operator
    --prime1;
    cout << "Prime1 after prefix --: " << prime1.getNumber() << endl;

    // Decrement prime2 using the postfix decrement operator
    PrimeNumber prime4 = prime2--;
    cout << "Prime2 after postfix --: " << prime2.getNumber() << endl;
    cout << "Prime4 (postfix result): " << prime4.getNumber() << endl;

    return 0;
}

