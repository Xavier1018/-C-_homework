#include<iostream>
using namespace std;

class HotDogStand
{
public:
    // Constructor to initialize the HotDogStand with ID and initial hot dogs sold
    HotDogStand(int ID, int hotDogSold) : standID(ID), hotDogSold(hotDogSold) {}

    // Method to increment the number of hot dogs sold by one
    void JustSold();

    // Method to get the current number of hot dogs sold by the stand
    int getHotDogSold() const;

    // Static method to get the total number of hot dogs sold by all stands
    static int getTotalHotDogSold();

private:
    int standID; // ID of the hot dog stand
    int hotDogSold; // Number of hot dogs sold by this stand
    static int totalHotDogSold; // Total number of hot dogs sold by all stands
};

// Method definition to increment the number of hot dogs sold by one
void HotDogStand::JustSold() {
    hotDogSold++; // Increment the number of hot dogs sold by this stand
    totalHotDogSold++; // Increment the total number of hot dogs sold by all stands
}

// Method definition to get the current number of hot dogs sold by the stand
int HotDogStand::getHotDogSold() const {
    return hotDogSold;
}

// Static method definition to get the total number of hot dogs sold by all stands
int HotDogStand::getTotalHotDogSold() {
    return totalHotDogSold;
}

// Initialization of the static member variable totalHotDogSold
int HotDogStand::totalHotDogSold = 0;

int main()
{
    // Create two hot dog stands with IDs 1 and 2 respectively, initially selling 0 hot dogs
    HotDogStand stand1(1, 0);
    HotDogStand stand2(2, 0);

    // Simulate selling hot dogs at each stand
    stand1.JustSold();
    stand2.JustSold();

    // Display the number of hot dogs sold by each stand and the total number of hot dogs sold by all stands
    cout << "Hot dogs sold by stand 1: " << stand1.getHotDogSold() << std::endl;
    cout << "Hot dogs sold by stand 2: " << stand2.getHotDogSold() << std::endl;
    cout << "Total hot dogs sold by all stands: " << HotDogStand::getTotalHotDogSold() << std::endl;

    return 0;
}

