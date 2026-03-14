#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "User.h"

class Librarian : public User {
public:
    Librarian();
    Librarian(int id, std::string n, std::string p);

    void showMenu() override;
};

#endif