//
// Created by Yed on 21/03/2022.
//

#ifndef BIBLIOTHEQUE_LIBRARY_H
#define BIBLIOTHEQUE_LIBRARY_H

#include "Author.h"
#include "Book.h"
#include <vector>

using namespace std;

class Library {

private:
    int nb_art = 0; // nombre d'oeuvres
    vector<Book> Arts; // liste des oeuvres
    vector<Author> Authors; // list des auteurs

public:
    Library(); //constructeur defaut
    Library(const vector<Book> &arts, const vector<Author> &authors);
    Library(Library &other) = delete; // singleton constructeur

    virtual ~Library();

    const vector<Book> &getArts() const;
    const vector<Author> &getAuthors() const;

    void setArts(const vector<Book> &arts);
    void setAuthors(const vector<Author> &authors);

    void operator=(const Library &) = delete; // singleton pas d'attribution par opérateur
    void add_Arts(const Book &arts );
    int add_Author(const Author &author);
    string research_author(const string &book_name) const;
    vector<Book> research_books(const string &author_name) const;
};


#endif //BIBLIOTHEQUE_LIBRARY_H
