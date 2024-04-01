#include<iostream>
using namespace std;

class Weight {
public:
    // Function declarations
    void setWeightPounds(double pounds);
    void setWeightKilograms(double kilograms);
    void setWeightOunces(double ounces);
    double getPounds();
    double getKilograms();
    double getOunces();
private:
    double pounds;
};

// Function to set weight in pounds
void Weight::setWeightPounds(double pounds) {
    this->pounds = pounds;
}

// Function to set weight in kilograms
void Weight::setWeightKilograms(double kilograms) {
    this->pounds = kilograms * 2.21; // Convert kilograms to pounds
}

// Function to set weight in ounces
void Weight::setWeightOunces(double ounces) {
    this->pounds = ounces / 16; // Convert ounces to pounds
}

// Function to get weight in pounds
double Weight::getPounds() {
    return pounds;
}

// Function to get weight in kilograms
double Weight::getKilograms() {
    return pounds / 2.21; // Convert pounds to kilograms
}

// Function to get weight in ounces
double Weight::getOunces() {
    return pounds * 16; // Convert pounds to ounces
}

int main() {
    Weight weight;

    // Set weight in pounds
    weight.setWeightPounds(10);

    // Get weight in pounds, kilograms, and ounces
    cout << "Weight in pounds: " << weight.getPounds() << endl;
    cout << "Weight in kilograms: " << weight.getKilograms() << endl;
    cout << "Weight in ounces: " << weight.getOunces() << endl;

    // Set weight in kilograms
    weight.setWeightKilograms(5);

    // Get weight in pounds, kilograms, and ounces
    cout << "\nWeight in pounds: " << weight.getPounds() << endl;
    cout << "Weight in kilograms: " << weight.getKilograms() << endl;
    cout << "Weight in ounces: " << weight.getOunces() << endl;

    // Set weight in ounces
    weight.setWeightOunces(160);

    // Get weight in pounds, kilograms, and ounces
    cout << "\nWeight in pounds: " << weight.getPounds() << endl;
    cout << "Weight in kilograms: " << weight.getKilograms() << endl;
    cout << "Weight in ounces: " << weight.getOunces() << endl;

    return 0;
}