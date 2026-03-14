#include "../include/LibrarySystem.h"
#include <iostream>

void LibrarySystem::addBook(const Book& book) {
    books.push_back(book);
}

void LibrarySystem::addMember(const Member& member) {
    members.push_back(member);
}

void LibrarySystem::showAllBooks() {
    if (books.empty()) {
        std::cout << "No books in the system." << std::endl;
        return;
    }

    for (int i = 0; i < books.size(); i++) {
        books[i].display();
    }
}

void LibrarySystem::searchByTitle(std::string title) {
    bool found = false;

    for (int i = 0; i < books.size(); i++) {
        if (books[i].getTitle() == title) {
            books[i].display();
            found = true;
        }
    }

    if (!found) {
        std::cout << "Book not found." << std::endl;
    }
}

Book* LibrarySystem::findBookById(int bookId) {
    for (int i = 0; i < books.size(); i++) {
        if (books[i].getBookId() == bookId) {
            return &books[i];
        }
    }
    return nullptr;
}

Member* LibrarySystem::findMemberById(int memberId) {
    for (int i = 0; i < members.size(); i++) {
        if (members[i].getUserId() == memberId) {
            return &members[i];
        }
    }
    return nullptr;
}

bool LibrarySystem::borrowBook(int memberId, int bookId) {
    Book* book = findBookById(bookId);
    Member* member = findMemberById(memberId);

    if (member->getBorrowedBooks().size() >= 5) {
        std::cout << "Borrow limit reached (5 books)." << std::endl;
        return false;
    }

    if (book == nullptr || member == nullptr) {
        std::cout << "Member or book not found." << std::endl;
        return false;
    }

    if (book->getStatus() != "Available") {
        std::cout << "Book is not available." << std::endl;
        return false;
    }

    book->setStatus("Borrowed");
    book->setBorrowedBy(memberId);
    member->addBorrowedBook(bookId);

    std::cout << "Book borrowed successfully." << std::endl;
    return true;
}

bool LibrarySystem::returnBook(int memberId, int bookId) {
    Book* book = findBookById(bookId);
    Member* member = findMemberById(memberId);

    if (book == nullptr || member == nullptr) {
        std::cout << "Member or book not found." << std::endl;
        return false;
    }

    if (book->getBorrowedBy() != memberId) {
        std::cout << "This member did not borrow that book." << std::endl;
        return false;
    }

    book->setStatus("Available");
    book->setBorrowedBy(-1);
    member->removeBorrowedBook(bookId);

    std::cout << "Book returned successfully." << std::endl;
    return true;
}

bool LibrarySystem::reserveBook(int memberId, int bookId) {
    Book* book = findBookById(bookId);
    Member* member = findMemberById(memberId);

    if (book == nullptr || member == nullptr) {
        std::cout << "Member or book not found." << std::endl;
        return false;
    }

    if (book->getStatus() != "Borrowed") {
        std::cout << "Only borrowed books can be reserved." << std::endl;
        return false;
    }

    if (book->getReservedBy() != -1) {
        std::cout << "Book already reserved." << std::endl;
        return false;
    }

    book->setReservedBy(memberId);

    std::cout << "Book reserved successfully." << std::endl;
    return true;
}