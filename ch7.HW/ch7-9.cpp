#include<iostream>
#include<string>
using namespace std;

class ZipCode {
public:
    ZipCode(int code);
    ZipCode(const string& barcode);

    int getZipCode() const;
    string getBarcode() const;

private:
    string barcode;
    int zipcode;

    int decodeDigit(const string& digit) const;
    string encodeDigit(int digit) const;
};

// Constructor to initialize ZipCode from integer ZIP code
ZipCode::ZipCode(int code) : zipcode(code) {
    // Construct barcode from ZIP code
    barcode = encodeDigit(0) + encodeDigit(code / 10000) + encodeDigit(code / 1000 % 10) + encodeDigit(code / 100 % 10) + encodeDigit(code / 10 % 10) + encodeDigit(code % 10) + encodeDigit(0);
}

// Constructor to initialize ZipCode from barcode string
ZipCode::ZipCode(const string& barcode) : barcode(barcode) {
    // Decode barcode into ZIP code
    zipcode = decodeDigit(barcode.substr(1, 5)) * 10000 + decodeDigit(barcode.substr(6, 5)) * 1000 + decodeDigit(barcode.substr(11, 5)) * 100 + decodeDigit(barcode.substr(16, 5)) * 10 + decodeDigit(barcode.substr(21, 5));
}

// Function to get the ZIP code as an integer
int ZipCode::getZipCode() const {
    return zipcode;
}

// Function to get the barcode format of the ZIP code
string ZipCode::getBarcode() const {
    return barcode;
}

// Helper function to decode a single digit from barcode
int ZipCode::decodeDigit(const string& digit) const {
    int value = 0;
    // Convert binary digit to decimal
    for (size_t i = 0; i < digit.size(); ++i) {
        if (digit[i] == '1') {
            value += 1 << (digit.size() - 1 - i);
        }
    }
    // Handle special case where value is 11, representing 0
    return (value == 11) ? 0 : value;
}

// Helper function to encode a single digit into barcode
string ZipCode::encodeDigit(int digit) const {
    string binary;
    // Encode decimal digit to binary
    if (digit == 0) {
        binary = "11000";  // Special encoding for 0
    }
    else {
        while (digit > 0) {
            binary = ((digit % 2 == 0) ? '0' : '1') + binary;
            digit /= 2;
        }
        // Add leading zeros to make it 5 digits
        while (binary.size() < 5) {
            binary = "0" + binary;
        }
    }
    return binary;
}

int main() {
    // Test program
    ZipCode zip1(99504);
    cout << "Barcode for zip code 99504: " << zip1.getBarcode() << endl;

    ZipCode zip2("110100101000101011000010011");
    cout << "Zip code for barcode 110100101000101011000010011: " << zip2.getZipCode() << endl;

    return 0;
}
