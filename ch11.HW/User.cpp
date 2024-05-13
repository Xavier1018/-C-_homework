#include "User.h"

bool User::Login(std::string username, std::string password) {
    int clearance = Security::validate(username, password); // Validate credentials using Security class
    return (clearance == 1 || clearance == 2); // Return true if clearance level is 1 (administrator) or 2 (user)
}
