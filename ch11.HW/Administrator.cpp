#include "Administrator.h"

bool Administrator::Login(std::string username, std::string password) {
    int clearance = Security::validate(username, password); // Validate credentials using Security class
    return (clearance == 1); // Return true if clearance level is 1 (administrator)
}
