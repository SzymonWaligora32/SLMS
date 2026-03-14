#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    int userId;
    std::string name;
    std::string password;

public:
    User();
    User(int id, std::string n, std::string p);

    int getUserId();
    std::string getName();
    bool login(std::string inputPassword);

    virtual void showMenu();
};

#endif