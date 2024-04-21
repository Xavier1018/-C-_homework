#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Grade {
public:
    Grade(int min, int max) : min_grade(min), max_grade(max) {}
    void input();    // Function to input grades
    void compute();  // Function to compute histogram
    void display();  // Function to display histogram
private:
    vector<int> grades;     // Renamed to avoid conflict
    vector<int> histogram;  // Vector to store histogram data
    int min_grade;          // Minimum grade allowed
    int max_grade;          // Maximum grade allowed
};

// Function to input grades
void Grade::input() {
    int grade;
    cout << "Enter student's grade " << min_grade << "-" << max_grade
        << " or outside this range to end: \n";
    while (cin >> grade && grade != -1) {
        if (grade >= min_grade && grade <= max_grade) {
            grades.push_back(grade);
        }
        else {
            cout << "Invalid grade. Enter a grade between " << min_grade
                << " and " << max_grade << ", or -1 to end: ";
            continue; // Prompt user again for valid input
        }
    }
}

// Function to compute histogram
void Grade::compute() {
    if (grades.empty()) {
        cout << "No grade entered." << endl;
        return;
    }

    histogram.resize(max_grade - min_grade + 1, 0);  // Resize histogram vector
    for (int g : grades) {
        histogram[g - min_grade]++;  // Increment the histogram
    }
}

// Function to display histogram
void Grade::display() {
    for (size_t i = 0; i < histogram.size(); ++i) {
        cout << histogram[i] << " grade(s) of " << i + min_grade << endl;
    }
}

int main() {
    int min_grade, max_grade;
    cout << "Enter the minimum grade and maximum grade: ";
    cin >> min_grade >> max_grade;

    Grade grades(min_grade, max_grade);  // Create Grade object
    grades.input();   // Input grades
    grades.compute(); // Compute histogram
    grades.display(); // Display histogram
    return 0;
}

