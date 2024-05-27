#include "employee.h"
#include <iostream>

using namespace std;

Employee::Employee() : name(""), ssn(""), net_pay(0.0) {}

Employee::Employee(string the_name, string the_ssn) : name(the_name), ssn(the_ssn), net_pay(0.0) {}

string Employee::get_name() const {
    return name;
}

string Employee::get_ssn() const {
    return ssn;
}

double Employee::get_net_pay() const {
    return net_pay;
}

void Employee::set_name(string new_name) {
    name = new_name;
}

void Employee::set_ssn(string new_ssn) {
    ssn = new_ssn;
}

void Employee::set_net_pay(double new_net_pay) {
    net_pay = new_net_pay;
}

void Employee::print_check() const {
    cout << "ERROR: print_check() is not implemented for base Employee class" << endl;
}
