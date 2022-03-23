//
// Created by Yed on 21/03/2022.
//

#ifndef BIBLIOTHEQUE_BOOK_H
#define BIBLIOTHEQUE_BOOK_H

#include <iostream>
#include "Author.h"

using namespace std;

class Book {

private:
    string book_name;
    Author book_author;
    string kind;
    enum type{ bd, roman, poche};

public:
    virtual ~Book();
    Book(const string &bookName, Author bookAuthor);

    const string &getBookName() const;
    const Author &getBookAuthor() const;

    void setBookName(const string &bookName);
    void setBookAuthor(const Author &bookAuthor);
};


#endif //BIBLIOTHEQUE_BOOK_H
