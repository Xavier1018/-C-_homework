#include<iostream>
using namespace std;

// Function definition: Convert pace (minutes and seconds per mile) to miles per hour
double convertToMPH(int minute, int second) {
    // Convert minutes to seconds, add seconds, and get total seconds per mile
    double paceSecond = minute * 60 + second;

    // Calculate miles per hour and return
    return 3600.0 / paceSecond;
}

// Function definition: Convert kilometers per hour to miles per hour
double convertToMPH(double kph) {
    // Convert kilometers per hour to miles per hour and return
    return kph / 1.61;
}

int main()
{
    // Declare variables to store user input data
    int minutes;
    int seconds;

    // Prompt the user to enter the pace (minutes and seconds per mile)
    cout << "Enter your speed in terms of a pace (minutes and seconds per mile, e.g., 5:30 mile): ";
    // Read minutes and seconds input from the user
    cin >> minutes >> seconds;

    // Call function to convert pace to miles per hour and print the result
    double mph = convertToMPH(minutes, seconds);
    cout << "Speed in miles per hour: " << mph << endl;

    // Declare variable to store user input data
    double kph;
    // Prompt the user to enter the speed in kilometers per hour
    cout << "Enter your speed in kilometers per hour: ";
    // Read kilometers per hour input from the user
    cin >> kph;

    // Call function to convert kilometers per hour to miles per hour and print the result
    mph = convertToMPH(kph);
    cout << "Speed in miles per hour: " << mph << endl;

    return 0;
}

