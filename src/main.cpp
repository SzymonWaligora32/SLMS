#include <iostream>
#include "../include/LibrarySystem.h"

int main() {
    LibrarySystem library;
    int choice;
    int memberId = 1; // simple fixed member for now
    int bookId;
    std::string title;

    library.addBook(Book(101, "Harry Potter", "J.K. Rowling"));
    library.addBook(Book(102, "The Hobbit", "J.R.R. Tolkien"));
    library.addBook(Book(103, "1984", "George Orwell"));

    library.addMember(Member(1, "Dave", "dave123"));

    do {
        std::cout << "\n===== Smart Library Management System =====" << std::endl;
        std::cout << "1. Show all books" << std::endl;
        std::cout << "2. Search book by title" << std::endl;
        std::cout << "3. Borrow book" << std::endl;
        std::cout << "4. Return book" << std::endl;
        std::cout << "5. Reserve book" << std::endl;
        std::cout << "6. View borrowed books" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                library.showAllBooks();
                break;

            case 2:
                std::cin.ignore();
                std::cout << "Enter exact title: ";
                std::getline(std::cin, title);
                library.searchByTitle(title);
                break;

            case 3:
                std::cout << "Enter book ID to borrow: ";
                std::cin >> bookId;
                library.borrowBook(memberId, bookId);
                break;

            case 4:
                std::cout << "Enter book ID to return: ";
                std::cin >> bookId;
                library.returnBook(memberId, bookId);
                break;

            case 5:
                std::cout << "Enter book ID to reserve: ";
                std::cin >> bookId;
                library.reserveBook(memberId, bookId);
                break;

            case 6: {
                Member* member = library.findMemberById(memberId);
                if (member != nullptr) {
                    member->viewBorrowedBooks();
                }
                break;
            }

            case 0:
                std::cout << "Exiting program..." << std::endl;
                break;

            default:
                std::cout << "Invalid choice." << std::endl;
        }

    } while (choice != 0);

    return 0;
}