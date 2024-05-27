#include "salariedemployee.h"
#include <iostream>
using namespace std;

// Default constructor initializes salary to 0.0
SalariedEmployee::SalariedEmployee() : salary(0.0) {}

// Parameterized constructor initializes member variables
SalariedEmployee::SalariedEmployee(string the_name, string the_ssn, double the_weekly_salary) : Employee(the_name, the_ssn), salary(the_weekly_salary) {}

// Mutator function to set the salary
void SalariedEmployee::set_salary(double new_salary) {
    salary = new_salary;
}

// Accessor function to get the salary
double SalariedEmployee::get_salary() const {
    return salary;
}

// Function to print a check, displays an error message
void SalariedEmployee::print_check() const {
    cout << "Error: Cannot print check for base Salaried Employee." << endl;
}
