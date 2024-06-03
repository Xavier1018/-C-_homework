#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "salariedemployee.h" // Include necessary header for base class
#include <string>
using namespace std;

class Administrator : public SalariedEmployee {
public:
    // Constructors
    Administrator(); // Default constructor
    Administrator(string the_name, string the_ssn, double the_salary, string the_title, string the_area, string the_supervisor); // Parameterized constructor

    // Accessor and mutator functions for title
    void set_title(string new_title);
    string get_title() const;

    // Accessor and mutator functions for area
    void set_area(string new_area);
    string get_area() const;

    // Accessor and mutator functions for supervisor
    void set_supervisor(string new_supervisor);

    // Function to read data from user input
    void read_data();

    // Function to print administrator's information
    void print() const;

    // Overridden function to print a check
    void print_check() const;

private:
    // Member variables specific to Administrator
    string title; // Title of the administrator
    string area; // Area of responsibility
    string supervisor; // Name of immediate supervisor
};

#endif // ADMINISTRATOR_H
