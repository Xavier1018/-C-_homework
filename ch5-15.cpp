#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to generate random numbers for digits 0 to 9
int generateRandom() {
    return rand() % 3 + 1; // Generates random numbers from 1 to 3
}

int main() {
    srand(time(0)); // Initialize random seed

    int PIN[5] = { 1, 2, 3, 4, 5 }; // Actual PIN code

    int random[10];
    // Generate random numbers and store them in the random array
    for (int i = 0; i < 10; i++) {
        random[i] = generateRandom();
    }

    cout << "Random Numbers:\n";
    // Output the generated random numbers
    for (int i = 0; i < 10; i++) {
        cout << "Digit " << i << ": " << random[i] << endl;
    }

    int response;
    cout << "Enter your response: ";
    cin >> response; // Accept user's response

    int transResponse = 0;
    int remainingResponse = response;
    int multiplier = 1;
    // Convert user's response to the corresponding digits based on random numbers
    while (remainingResponse > 0) {
        int digit = remainingResponse % 10;
        transResponse += random[digit] * multiplier;
        multiplier *= 10;
        remainingResponse /= 10;
    }

    // Compare the converted response with the actual PIN code to determine authentication
    if (transResponse == PIN[0] * 10000 + PIN[1] * 1000 + PIN[2] * 100 + PIN[3] * 10 + PIN[4]) {
        cout << "Authentication successful. Welcome!\n";
    }
    else {
        cout << "Authentication failed. Access denied.\n";
    }

    return 0;
}


