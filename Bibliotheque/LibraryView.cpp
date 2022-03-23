//
// Created by Yed on 21/03/2022.
//

#include "LibraryView.h"

LibraryView::LibraryView() {

}

LibraryView::~LibraryView() {

}

// montre tous les livres de la bilbiothèque aisnsi que leur auteur, les doublons
void LibraryView::show_arts(const Library *curr_lib) {
    size_t i = 0;
    cout << "----------------SHOWING LIST BOOKS----------------" << endl;
    while (i != curr_lib->getArts().size()) {
        cout << curr_lib->getArts()[i].getBookName() << " written by "
             << curr_lib->getArts()[i].getBookAuthor().getFirstname() << " "
             << curr_lib->getArts()[i].getBookAuthor().getLastname() << endl;
        i++;
    }
}

void LibraryView::show_authors(const Library *curr_lib) {
    size_t i = 0;
    cout << "----------------SHOWING LIST AUTHORS----------------" << endl;
    while (i != curr_lib->getAuthors().size()) {
        cout << "- " << curr_lib->getAuthors()[i].getLastname() << " " << curr_lib->getAuthors()[i].getFirstname()
             << endl;
        i++;
    }
}

void LibraryView::show_search_result_author(const Library *curr_lib, const string &book_name) {
    string tmp = curr_lib->research_author(book_name);
    cout << "----------------SEARCHING BOOK'S AUTHOR----------------" << endl;
    if (tmp.compare("book not found") == 0)
        cout << book_name << "hasn't been found" << endl;
    cout << book_name << " has been written by " << tmp << endl;
}

void LibraryView::show_search_result_books(const Library *curr_lib, const string &author_name) {
    cout << "test" << endl;
    vector<Book> tmp = curr_lib->research_books(author_name);
    size_t i = 0;
    cout << "----------------SEARCHING AUTHOR'S CREATIONS----------------" << endl;
    cout << author_name << " has written following books : " << endl;
    while (i < tmp.size()) {
        cout << "-" << tmp[i].getBookName() << endl;
        i++;
    }
}

