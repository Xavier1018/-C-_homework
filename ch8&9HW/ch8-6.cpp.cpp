#include<iostream>
using namespace std;

class MyInteger
{
public:
    // Constructor to initialize the integer value
    MyInteger(int val) : value(val) {}

    // Setter function to update the integer value
    void setInteger(int val) { value = val; }

    // Getter function to retrieve the integer value
    int getInteger() const { return value; }

    // Overloaded subscript operator [] to access individual digits of the integer
    int operator[](int index) const;

private:
    int value; // Integer value
};

// Definition of the overloaded subscript operator []
int MyInteger::operator[](int index) const {
    // Check if the index is non-negative
    if (index >= 0) {
        int temp = value;
        // Count the number of digits in the integer
        int numDigits = 0;
        while (temp > 0) {
            temp /= 10;
            numDigits++;
        }
        // Check if the index is within the range of digits
        if (index < numDigits) {
            temp = value;
            // Extract the digit at the specified index
            for (int i = 0; i < index; i++) {
                temp /= 10;
            }
            return temp % 10; // Return the digit at the specified index
        }
    }
    return -1; // Return -1 if the index is out of range or no such digit exists
}

int main()
{
    // Create an object of MyInteger with an initial value of 12345
    MyInteger myInt(12345);

    // Display the original number
    cout << "Original number: " << myInt.getInteger() << endl;

    // Access and display individual digits using the overloaded subscript operator []
    cout << "Digit at index 0: " << myInt[0] << endl;
    cout << "Digit at index 1: " << myInt[1] << endl;
    cout << "Digit at index 2: " << myInt[2] << endl;
    cout << "Digit at index 3: " << myInt[3] << endl;
    cout << "Digit at index 4: " << myInt[4] << endl;
    cout << "Digit at index 5: " << myInt[5] << endl; // Index out of range

    return 0;
}

