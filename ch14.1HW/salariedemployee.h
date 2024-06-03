#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include "employee.h" // Include necessary header for base class

class SalariedEmployee : public Employee {
public:
    // Constructors
    SalariedEmployee(); // Default constructor
    SalariedEmployee(string the_name, string the_ssn, double the_weekly_salary); // Parameterized constructor

    // Mutator function for setting the employee's salary
    void set_salary(double new_salary);

    // Accessor function for getting the employee's salary
    double get_salary() const;

    // Overridden function to print a check
    void print_check() const;

protected: // Changed access level from private to protected
    // Member variable for salary
    double salary;
};

#endif // SALARIEDEMPLOYEE_H
