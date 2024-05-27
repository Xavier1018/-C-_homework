// administrator.cpp
#include "administrator.h"
#include <iostream>
using namespace std;

Administrator::Administrator() : title(""), area(""), supervisor("") {}

Administrator::Administrator(string the_name, string the_ssn, double the_salary, string the_title, string the_area, string the_supervisor)
    : SalariedEmployee(the_name, the_ssn, the_salary), title(the_title), area(the_area), supervisor(the_supervisor) {}

void Administrator::set_title(string new_title) {
    title = new_title;
}

string Administrator::get_title() const {
    return title;
}

void Administrator::set_area(string new_area) {
    area = new_area;
}

string Administrator::get_area() const {
    return area;
}

void Administrator::set_supervisor(string new_supervisor) {
    supervisor = new_supervisor;
}

void Administrator::read_data() {
    cout << "Enter administrator's name: ";
    cin >> name;
    cout << "Enter administrator's SSN: ";
    cin >> ssn;
    cout << "Enter administrator's annual salary: ";
    cin >> salary;
    cout << "Enter administrator's title: ";
    cin >> title;
    cout << "Enter administrator's area: ";
    cin >> area;
    cout << "Enter administrator's supervisor: ";
    cin >> supervisor;
}

void Administrator::print() const {
    cout << "Name: " << name << endl;
    cout << "SSN: " << ssn << endl;
    cout << "Title: " << title << endl;
    cout << "Area: " << area << endl;
    cout << "Supervisor: " << supervisor << endl;
    cout << "Salary: " << salary << endl;
}

void Administrator::print_check() const {
    cout << "Pay to the order of " << name << endl;
    cout << "Amount: " << salary << endl;
    cout << "Signed: " << supervisor << endl;
}
