#include<iostream>
#include<string>
using namespace std;

class Pizza {
public:
    // Constructor
    Pizza(const string& pizzaType, const string& pizzaSize, int pizzaNum)
        : type(pizzaType), size(pizzaSize), num(pizzaNum) {}

    // Member functions
    void outputDescription();
    double computePrice();

private:
    const string type;   // Type of the pizza
    const string size;   // Size of the pizza
    int num;             // Number of pizzas
};

// Output the description of the pizza
void Pizza::outputDescription() {
    cout << "Pizza type: " << type << endl;
    cout << "Pizza size: " << size << endl;
    cout << "Number of pizza: " << num << endl;
}

// Compute the price of the pizza
double Pizza::computePrice() {
    double basePrice = 0.0;
    if (size == "Small") {
        basePrice = 10.0;
    }
    else if (size == "Medium") {
        basePrice = 14.0;
    }
    else if (size == "Large") {
        basePrice = 17.0;
    }
    if (num < 0) {
        cout << "Error: Number of pizzas cannot be negative." << endl;
    }

    return basePrice + (2 * num);
}

int main() {
    // Create Pizza objects
    Pizza pizza1("Deep Dish", "Large", 1);
    Pizza pizza2("Hand Tossed", "Medium", 2);
    Pizza pizza3("Pan", "Small", 3);

    // Output description and price for each pizza
    cout << "Pizza 1: " << endl;
    pizza1.outputDescription();
    cout << "Price: $" << pizza1.computePrice() << endl;

    cout << "Pizza 2: " << endl;
    pizza2.outputDescription();
    cout << "Price: $" << pizza2.computePrice() << endl;

    cout << "Pizza 3: " << endl;
    pizza3.outputDescription();
    cout << "Price: $" << pizza3.computePrice() << endl;

    return 0;
}

