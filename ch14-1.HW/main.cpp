#include "administrator.h"
#include <iostream>
using namespace std;

int main() {
    // Create an instance of Administrator
    Administrator admin;

    // Read data for the administrator
    admin.read_data();

    // Print administrator details
    cout << "\nAdministrator details:\n";
    admin.print();

    // Ensure net pay is set before printing the check
    admin.set_net_pay(admin.get_salary());

    // Print a check for the administrator
    cout << "\nPrint check:\n";
    admin.print_check();

    return 0;
}
