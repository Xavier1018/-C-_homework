#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

// Class definition for BoxOfProduce
class BoxOfProduce {
public:
    // Member functions
    void Produce(); // Function to fill the box with random produce
    void display(); // Function to display the contents of the box
    void change(int index, const std::string& newItem); // Function to change the produce at a specific index

private:
    string produce[3]; // Array to store produce items
};

// Function to fill the box with random produce
void BoxOfProduce::Produce() {
    srand(time(NULL)); // Seed the random number generator
    string item[] = { "Broccoli","Tomato","Kiwi","Kale","Tomatillo" }; // List of produce items
    for (int i = 0; i < 3; i++) {
        produce[i] = item[rand() % 5]; // Select a random produce item and add it to the box
    }
}

// Function to display the contents of the box
void BoxOfProduce::display() {
    cout << "Box contents:\n";
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". " << produce[i] << endl; // Display each produce item in the box
    }
}

// Function to change the produce at a specific index
void BoxOfProduce::change(int index, const std::string& newItem) {
    if (index >= 1 && index <= 3) { // Check if the index is valid
        produce[index - 1] = newItem; // Update the produce at the specified index
    }
}

// Main function
int main() {
    char choice;
    do {
        BoxOfProduce box; // Create a box object
        box.Produce(); // Fill the box with produce
        box.display(); // Display the initial contents of the box

        int index;
        string newItem;

        cout << "Enter the index of the item you want to substitute (1-3): ";
        cin >> index; // Input the index of the item to be substituted

        cout << "Enter the new item: ";
        cin >> newItem; // Input the new item

        box.change(index, newItem); // Change the produce item at the specified index

        cout << "Final contents of the box: ";
        box.display(); // Display the final contents of the box after substitution

        cout << "Do you want to create another box? (y/n): ";
        cin >> choice; // Ask the user if they want to create another box
    } while (choice == 'y' || choice == 'Y'); // Repeat the loop if the user chooses 'y' or 'Y'

    return 0; // Return 0 to indicate successful completion of the program
}
