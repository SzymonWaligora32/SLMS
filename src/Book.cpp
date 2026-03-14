#include "../include/Book.h"
#include <iostream>

Book::Book() {
    bookId = 0;
    title = "";
    author = "";
    status = "Available";
    borrowedBy = -1;
    reservedBy = -1;
}

Book::Book(int id, std::string t, std::string a) {
    bookId = id;
    title = t;
    author = a;
    status = "Available";
    borrowedBy = -1;
    reservedBy = -1;
}

int Book::getBookId() {
    return bookId;
}

std::string Book::getTitle() {
    return title;
}

std::string Book::getAuthor() {
    return author;
}

std::string Book::getStatus() {
    return status;
}

int Book::getBorrowedBy() {
    return borrowedBy;
}

void Book::setStatus(std::string newStatus) {
    status = newStatus;
}

void Book::setBorrowedBy(int memberId) {
    borrowedBy = memberId;
}

void Book::setReservedBy(int memberId) {
    reservedBy = memberId;
}

int Book::getReservedBy() {
    return reservedBy;
}

void Book::display() {
    std::cout << "ID: " << bookId
              << " | Title: " << title
              << " | Author: " << author
              << " | Status: " << status;

    if (borrowedBy != -1) {
        std::cout << " | Borrowed By Member ID: " << borrowedBy;
    }

    if (reservedBy != -1) {
        std::cout << " | Reserved By Member ID: " << reservedBy;
    }

    std::cout << std::endl;
}