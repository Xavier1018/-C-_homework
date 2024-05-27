// administrator.h
#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "salariedemployee.h"
#include <string>
using namespace std;

class Administrator : public SalariedEmployee {
public:
    Administrator();
    Administrator(string the_name, string the_ssn, double the_salary, string the_title, string the_area, string the_supervisor);
    void set_title(string new_title);
    string get_title() const;
    void set_area(string new_area);
    string get_area() const;
    void set_supervisor(string new_supervisor);
    void read_data();
    void print() const;
    void print_check() const;

private:
    string title;
    string area;
    string supervisor;
};

#endif // ADMINISTRATOR_H





