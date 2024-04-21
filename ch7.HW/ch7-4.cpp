#include <iostream>
using namespace std;

class HotDogStand {
private:
    int standID;
    int hotDogsSold;
    static int totalHotDogsSold;

public:
    HotDogStand(int id, int sold) : standID(id), hotDogsSold(sold) {}

    void justSold() {
        hotDogsSold++;
        totalHotDogsSold++;
    }

    int getHotDogsSold() const {
        return hotDogsSold;
    }

    static int getTotalHotDogsSold() {
        return totalHotDogsSold;
    }
};

int HotDogStand::totalHotDogsSold = 0;

int main() {
    // Create three hot dog stands
    HotDogStand stand1(1, 0);
    HotDogStand stand2(2, 0);
    HotDogStand stand3(3, 0);

    // Simulate selling hot dogs
    stand1.justSold();
    stand1.justSold();
    stand2.justSold();
    stand3.justSold();
    stand3.justSold();
    stand3.justSold();

    // Display number of hot dogs sold by each stand
    cout << "Stand 1 sold: " << stand1.getHotDogsSold() << " hot dogs\n";
    cout << "Stand 2 sold: " << stand2.getHotDogsSold() << " hot dogs\n";
    cout << "Stand 3 sold: " << stand3.getHotDogsSold() << " hot dogs\n";

    // Display total number of hot dogs sold
    cout << "Total hot dogs sold by all stands: " << HotDogStand::getTotalHotDogsSold() << " hot dogs\n";

    return 0;
}


