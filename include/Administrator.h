#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "User.h"

class Administrator : public User {
public:
    Administrator();
    Administrator(int id, std::string n, std::string p);

    void showMenu() override;
};

#endif