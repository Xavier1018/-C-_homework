#include "Security.h"

int Security::validate(std::string username, std::string password) {
    // Validation logic for username and password
    if ((username == "abbott") && (password == "monday"))
        return 1; // Return clearance level 1 for administrator
    if ((username == "costello") && (password == "tuesday"))
        return 2; // Return clearance level 2 for user
    return 3; // Return clearance level 3 for invalid credentials
}
