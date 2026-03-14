#include "../include/User.h"
#include <iostream>

User::User() {
    userId = 0;
    name = "";
    password = "";
}

User::User(int id, std::string n, std::string p) {
    userId = id;
    name = n;
    password = p;
}

int User::getUserId() {
    return userId;
}

std::string User::getName() {
    return name;
}

bool User::login(std::string inputPassword) {
    return inputPassword == password;
}

void User::showMenu() {
    std::cout << "General user menu" << std::endl;
}