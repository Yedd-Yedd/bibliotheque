//
// Created by Yed on 21/03/2022.
//

#ifndef BIBLIOTHEQUE_AUTHOR_H
#define BIBLIOTHEQUE_AUTHOR_H

#include <iostream>

using namespace std;

class Author {

private:
    string firstname;
    string lastname;

public:
    Author(const string &firstname, const string &lastname);
    virtual ~Author();

    const string &getFirstname() const;
    const string &getLastname() const;

    void setFirstname(const string &firstname);
    void setLastname(const string &lastname);
};


#endif //BIBLIOTHEQUE_AUTHOR_H
