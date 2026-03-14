#include "../include/Member.h"
#include <iostream>

Member::Member() : User() {
}

Member::Member(int id, std::string n, std::string p) : User(id, n, p) {
}

void Member::addBorrowedBook(int bookId) {
    borrowedBooks.push_back(bookId);
}

void Member::removeBorrowedBook(int bookId) {
    for (int i = 0; i < borrowedBooks.size(); i++) {
        if (borrowedBooks[i] == bookId) {
            borrowedBooks.erase(borrowedBooks.begin() + i);
            break;
        }
    }
}

void Member::viewBorrowedBooks() {
    if (borrowedBooks.empty()) {
        std::cout << "No borrowed books." << std::endl;
        return;
    }

    std::cout << "Borrowed Book IDs: ";
    for (int i = 0; i < borrowedBooks.size(); i++) {
        std::cout << borrowedBooks[i] << " ";
    }
    std::cout << std::endl;
}

std::vector<int> Member::getBorrowedBooks() {
    return borrowedBooks;
}

void Member::showMenu() {
    std::cout << "Member Menu" << std::endl;
    std::cout << "1. Search Book" << std::endl;
    std::cout << "2. Borrow Book" << std::endl;
    std::cout << "3. Return Book" << std::endl;
    std::cout << "4. View Borrowed Books" << std::endl;
}