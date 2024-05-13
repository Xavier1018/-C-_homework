#include <iostream>
#include <string>
using namespace std;

class Television {
public:
    // Constructor with default values for parameters
    Television(string displayType = "LED", double dimension = 32.1, string* connectivitySupport = nullptr, int connectivityCount = 0)
        : displayType(displayType), dimension(dimension), connectivityCount(connectivityCount) {
        // Dynamically allocate memory for connectivitySupport if not nullptr
        if (connectivitySupport != nullptr) {
            this->connectivitySupport = new string[connectivityCount];
            for (int i = 0; i < connectivityCount; ++i) {
                this->connectivitySupport[i] = connectivitySupport[i];
            }
        }
        else {
            this->connectivitySupport = nullptr;
        }
    }

    // Destructor to release dynamically allocated memory
    ~Television() { delete[] connectivitySupport; }

    // Getter methods
    string getDisplayType() const { return displayType; }
    double getDimension() const { return dimension; }
    string* getConnectivitySupport() const { return connectivitySupport; }
    int getConnectivityCount() const { return connectivityCount; }

    // Setter methods
    void setDisplayType(const string type) { displayType = type; }
    void setDimension(const double dim) { dimension = dim; }
    void setConnectivitySupport(string* support, const int count);

private:
    // Member variables
    string displayType;
    double dimension;
    string* connectivitySupport;
    int connectivityCount;
};

// Method to set connectivity support
void Television::setConnectivitySupport(string* support, const int count) {
    // Delete existing connectivitySupport array
    delete[] connectivitySupport;
    // Allocate new memory and copy values
    connectivitySupport = new string[count];
    for (int i = 0; i < count; ++i) {
        connectivitySupport[i] = support[i];
    }
    connectivityCount = count;
}

int main() {
    int numTV;
    // Prompt user for the number of televisions
    cout << "Enter the number of televisions: ";
    cin >> numTV;

    // Dynamically allocate an array of Television objects
    Television* TV = new Television[numTV];

    // Loop to customize each television
    for (int i = 0; i < numTV; ++i) {
        cout << "\nTelevision " << i + 1 << ":\n";
        string type;
        double dim;
        // Default connectivity modes
        string defaultConnectivity[] = { "HDMI","USB","Wi-Fi" };
        // Create Television object with default values
        TV[i] = Television("LED", 32.0, defaultConnectivity, 3);

        char customize;
        // Ask user if customization is required
        cout << "Do you want to customize this TV (y/n): ";
        cin >> customize;

        if (customize == 'y' || customize == 'Y') {
            // Customize TV properties
            cout << "Enter the type: ";
            cin >> type;
            TV[i].setDisplayType(type);

            cout << "Enter the dimension: ";
            cin >> dim;
            TV[i].setDimension(dim);

            int numConnection;
            cout << "Enter the number of connectivity modes: ";
            cin >> numConnection;

            string* connectivity = new string[numConnection];
            // Input connectivity modes
            for (int j = 0; j < numConnection; ++j) {
                cin >> connectivity[j];
            }
            // Set connectivity support for TV
            TV[i].setConnectivitySupport(connectivity, numConnection);
            delete[] connectivity;
        }
    }

    // Display information about all TVs
    cout << "\nTV's information:\n";
    for (int i = 0; i < numTV; ++i) {
        cout << "\nTelevision " << i + 1 << ":\n";
        cout << "Display type: " << TV[i].getDisplayType() << endl;
        cout << "Dimension: " << TV[i].getDimension() << endl;
        cout << "Connectivity modes: ";
        string* connectivity = TV[i].getConnectivitySupport();
        for (int j = 0; j < TV[i].getCon

