#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee {
public:
    // Default constructor
    Employee();
    // Parameterized constructor
    Employee(string the_name, string the_ssn);
    // Accessor functions
    string get_name() const;
    string get_ssn() const;
    double get_net_pay() const;
    // Mutator functions
    void set_name(string new_name);
    void set_ssn(string new_ssn);
    void set_net_pay(double new_net_pay);
    // Virtual function to print a check
    virtual void print_check() const;

protected:
    // Member variables
    string name;  // Employee's name
    string ssn;   // Employee's social security number
    double net_pay;  // Employee's net pay
};

#endif // EMPLOYEE_H

