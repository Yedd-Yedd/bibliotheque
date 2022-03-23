//
// Created by Yed on 21/03/2022.
//

#include "Book.h"

Book::Book(const string &bookName, Author bookAuthor)
: book_name(bookName), book_author(bookAuthor) {
}

Book::~Book() {

}

const string &Book::getBookName() const {
    return book_name;
}


const Author &Book::getBookAuthor() const {
    return book_author;
}

void Book::setBookAuthor(const Author &bookAuthor) {
    book_author = bookAuthor;
}

void Book::setBookName(const string &bookName) {
    book_name = bookName;
}