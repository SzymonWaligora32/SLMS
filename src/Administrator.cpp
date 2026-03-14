#include "../include/Administrator.h"
#include <iostream>

Administrator::Administrator() : User() {
}

Administrator::Administrator(int id, std::string n, std::string p) : User(id, n, p) {
}

void Administrator::showMenu() {
    std::cout << "Administrator Menu" << std::endl;
    std::cout << "1. Create Account" << std::endl;
    std::cout << "2. Set Borrow Limit" << std::endl;
    std::cout << "3. Set Late Penalty" << std::endl;
}