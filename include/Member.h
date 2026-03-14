#ifndef MEMBER_H
#define MEMBER_H

#include "User.h"
#include <vector>

class Member : public User {
private:
    std::vector<int> borrowedBooks;

public:
    Member();
    Member(int id, std::string n, std::string p);

    void addBorrowedBook(int bookId);
    void removeBorrowedBook(int bookId);
    void viewBorrowedBooks();

    std::vector<int> getBorrowedBooks();

    void showMenu() override;
};

#endif