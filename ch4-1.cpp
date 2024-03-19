#include<iostream>
using namespace std;

// Function to take input from the user
void input(int& hour, int& minute) {
    cout << "Enter the time in 24 notation (hour, minute): ";
    cin >> hour >> minute;
}

// Function to convert 24-hour notation to 12-hour notation
void convert(int& hour, int& minute, char& period) {
    // Check if the hour is greater than or equal to 12 to determine if it's afternoon or morning
    if (hour >= 12) {
        period = 'P'; // Set period to 'P' for afternoon
        if (hour > 12) {
            hour = hour - 12; // Convert hour to 12-hour format (subtract 12 if it's greater than 12)
        }
    }
    else {
        period = 'A'; // Set period to 'A' for morning
        if (hour == 0) {
            hour = 12; // Convert midnight (0 hour) to 12 AM
        }
    }
}

// Function to display the converted time
void output(int hour, int minute, char period) {
    cout << "Converted time: " << hour << ":" << minute;
    // Display period based on the value of 'period' variable
    if (period == 'A') {
        cout << " A.M.";
    }
    else if (period == 'P') {
        cout << " P.M.";
    }
}

int main() {
    int hour, minute;
    char period;

    // Input function call
    input(hour, minute);

    // Convert function call
    convert(hour, minute, period);

    // Output function call
    output(hour, minute, period);

    return 0;
}

