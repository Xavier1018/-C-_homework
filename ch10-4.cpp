#include<iostream>
#include<string>
using namespace std;

class Subscriber {
public:
    // Constructor
    Subscriber(const string& subscriberName) : name(subscriberName), num(0), channelList(nullptr) {}

    // Destructor
    ~Subscriber() {
        if (channelList != nullptr) {
            delete[] channelList;
        }
    }

    // Method to input subscriber details including channel list
    void input();

    // Method to output subscriber details
    void output() const;

    // Method to reset channels and channelList
    void reset();

    // Overloaded assignment operator
    Subscriber& operator=(const Subscriber& other);

private:
    string name;    // Name of the subscriber
    int num;        // Number of channels subscribed to
    string* channelList;    // Array to store channel names
};

// Method to input subscriber details
void Subscriber::input() {
    cout << "Enter the number of channels: ";
    cin >> num;
    cin.ignore();

    channelList = new string[num];

    cout << "Enter the channel names: \n";
    for (int i = 0; i < num; i++) {
        cout << "Channel " << i + 1 << ": ";
        getline(cin, channelList[i]);
    }
}

// Method to output subscriber details
void Subscriber::output() const {
    cout << "Subscriber name: " << name << endl;
    cout << "Subscribed channels:\n";
    for (int i = 0; i < num; i++) {
        cout << "- " << channelList[i] << endl;
    }
}

// Method to reset channels and channelList
void Subscriber::reset() {
    num = 0;
    delete[] channelList;
    channelList = nullptr;
}

// Overloaded assignment operator
Subscriber& Subscriber::operator=(const Subscriber& other) {
    if (this != &other) {
        name = other.name;
        num = other.num;

        delete[] channelList;

        if (num > 0) {
            channelList = new string[num];
            for (int i = 0; i < num; i++) {
                channelList[i] = other.channelList[i];
            }
        }
        else {
            channelList = nullptr;
        }
    }
    return *this;
}

int main() {
    Subscriber subscriber("Joe");
    subscriber.input();
    subscriber.output();

    Subscriber subscriber2("Mary");
    subscriber2.input();
    subscriber2.output();

    return 0;
}
