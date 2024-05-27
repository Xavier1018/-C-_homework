// salariedemployee.cpp
#include "salariedemployee.h"
#include <iostream>
using namespace std;

SalariedEmployee::SalariedEmployee() : salary(0.0) {}

SalariedEmployee::SalariedEmployee(string the_name, string the_ssn, double the_weekly_salary) : Employee(the_name, the_ssn), salary(the_weekly_salary) {}

void SalariedEmployee::set_salary(double new_salary) {
    salary = new_salary;
}

double SalariedEmployee::get_salary() const {
    return salary;
}

void SalariedEmployee::print_check() const {
    cout << "Error: Cannot print check for base Salaried Employee." << endl;
}
