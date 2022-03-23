//
// Created by Yed on 21/03/2022.
//

#include "Author.h"

Author::~Author() {

}

Author::Author(const string &firstname, const string &lastname)
: firstname(firstname), lastname(lastname) {

}

const string &Author::getFirstname() const {
    return firstname;
}

void Author::setFirstname(const string &firstname) {
    Author::firstname = firstname;
}

const string &Author::getLastname() const {
    return lastname;
}

void Author::setLastname(const string &lastname) {
    Author::lastname = lastname;
}
