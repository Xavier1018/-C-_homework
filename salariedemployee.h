// salariedemployee.h
#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include "employee.h"

class SalariedEmployee : public Employee {
public:
    SalariedEmployee();
    SalariedEmployee(string the_name, string the_ssn, double the_weekly_salary);
    void set_salary(double new_salary);
    double get_salary() const;
    void print_check() const;

protected: // Changed private to protected
    double salary;
};

#endif // SALARIEDEMPLOYEE_H



