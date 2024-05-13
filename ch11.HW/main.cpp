#include <iostream>
#include "Administrator.h"
#include "User.h"

int main() {
    Administrator admin;
    User user;

    std::cout << "Testing Administrator login:\n";
    std::cout << "Login result for admin (abbott, monday): " << std::boolalpha << admin.Login("abbott", "monday") << std::endl;
    std::cout << "Login result for admin (costello, tuesday): " << std::boolalpha << admin.Login("costello", "tuesday") << std::endl;

    std::cout << "\nTesting User login:\n";
    std::cout << "Login result for user (abbott, monday): " << std::boolalpha << user.Login("abbott", "monday") << std::endl;
    std::cout << "Login result for user (costello, tuesday): " << std::boolalpha << user.Login("costello", "tuesday") << std::endl;

    return 0;
}
