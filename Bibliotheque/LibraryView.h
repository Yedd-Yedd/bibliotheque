//
// Created by Yed on 21/03/2022.
//

#ifndef BIBLIOTHEQUE_LIBRARYVIEW_H
#define BIBLIOTHEQUE_LIBRARYVIEW_H

#include "Library.h"

using namespace std;

class LibraryView {

private:

public:
    LibraryView();
    virtual ~LibraryView();

    void show_arts(const Library *curr_lib);
    void show_authors(const Library *curr_lib);
    void show_search_result_author(const Library *curr_lib, const string &book_name);
    void show_search_result_books(const Library *curr_lib, const string &author_name);

};


#endif //BIBLIOTHEQUE_LIBRARYVIEW_H
