#include<iostream>
using namespace std;

class Money {
public:
    // Function to set the dollars
    void setDollars(int dol);

    // Function to set the cents
    void setCents(int cen);

    // Function to calculate the total amount
    double amount();

private:
    int dollars;
    int cents;
};

// Implementation of setDollars function
void Money::setDollars(int dol) {
    dollars = dol;
}

// Implementation of setCents function
void Money::setCents(int cen) {
    cents = cen;
}

// Implementation of amount function
double Money::amount() {
    // Calculate total amount in dollars and cents
    return dollars + cents / 100.0;
}

int main() {
    Money money1;
    Money money2;

    // Set values for money1
    money1.setDollars(10);
    money1.setCents(50);

    // Set values for money2
    money2.setDollars(5);
    money2.setCents(75);

    // Print the amount for money1
    cout << "Money 1: $" << money1.amount() << endl;

    // Print the amount for money2
    cout << "Money 2: $" << money2.amount() << endl;

    return 0;
}
