#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    int bookId;
    std::string title;
    std::string author;
    std::string status;
    int borrowedBy;
    int reservedBy;

public:
    Book();
    Book(int id, std::string t, std::string a);

    int getBookId();
    std::string getTitle();
    std::string getAuthor();
    std::string getStatus();
    int getBorrowedBy();

    void setStatus(std::string newStatus);
    void setBorrowedBy(int memberId);

    void setReservedBy(int memberId);
    int getReservedBy();

    void display();
    
};

#endif