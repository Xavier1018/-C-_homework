#include "employee.h"
#include <iostream>

using namespace std;

// Default constructor
Employee::Employee() : name(""), ssn(""), net_pay(0.0) {}

// Parameterized constructor
Employee::Employee(string the_name, string the_ssn) : name(the_name), ssn(the_ssn), net_pay(0.0) {}

// Accessor function for getting the employee's name
string Employee::get_name() const {
    return name;
}

// Accessor function for getting the employee's social security number
string Employee::get_ssn() const {
    return ssn;
}

// Accessor function for getting the employee's net pay
double Employee::get_net_pay() const {
    return net_pay;
}

// Mutator function for setting the employee's name
void Employee::set_name(string new_name) {
    name = new_name;
}

// Mutator function for setting the employee's social security number
void Employee::set_ssn(string new_ssn) {
    ssn = new_ssn;
}

// Mutator function for setting the employee's net pay
void Employee::set_net_pay(double new_net_pay) {
    net_pay = new_net_pay;
}

// Virtual function to print a check
void Employee::print_check() const {
    cout << "ERROR: print_check() is not implemented for base Employee class" << endl;
}
