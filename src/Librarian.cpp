#include "../include/Librarian.h"
#include <iostream>

Librarian::Librarian() : User() {
}

Librarian::Librarian(int id, std::string n, std::string p) : User(id, n, p) {
}

void Librarian::showMenu() {
    std::cout << "Librarian Menu" << std::endl;
    std::cout << "1. Add Book" << std::endl;
    std::cout << "2. Remove Book" << std::endl;
    std::cout << "3. View Overdue Books" << std::endl;
}