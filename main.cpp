#include "administrator.h"
#include <iostream>
using namespace std;

int main() {
    Administrator admin;
    admin.read_data();
    cout << "\nAdministrator details:\n";
    admin.print();

    // Ensure net pay is set before printing the check
    admin.set_net_pay(admin.get_salary());

    cout << "\nPrint check:\n";
    admin.print_check();

    return 0;
}
