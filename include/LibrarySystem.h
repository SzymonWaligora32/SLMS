#ifndef LIBRARYSYSTEM_H
#define LIBRARYSYSTEM_H

#include "Book.h"
#include "Member.h"
#include <vector>
#include <string>

class LibrarySystem {
private:
    std::vector<Book> books;
    std::vector<Member> members;

public:
    void addBook(const Book& book);
    void addMember(const Member& member);

    void showAllBooks();
    void searchByTitle(std::string title);

    bool borrowBook(int memberId, int bookId);
    bool returnBook(int memberId, int bookId);
    bool reserveBook(int memberId, int bookId);

    Book* findBookById(int bookId);
    Member* findMemberById(int memberId);
};

#endif