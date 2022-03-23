//
// Created by Yed on 21/03/2022.
//

#include <cstring>
#include "Library.h"

Library::Library() {

}

Library::~Library() {

}

// constructeur en se basant par des vector déja créés
Library::Library(const vector<Book> &arts, const vector<Author> &authors) {
    this->setArts(arts);
    this->setAuthors(authors);
}

const vector<Book> &Library::getArts() const {
    return Arts;
}

const vector<Author> &Library::getAuthors() const {
    return Authors;
}

// les setters servent a remplir l'objet de liste
void Library::setArts(const vector<Book> &arts) {
    Arts = arts;
}

void Library::setAuthors(const vector<Author> &authors) {
    Authors = authors;
}

// on peut rajouter plusieurs fois le meme livre, les doublons d'une oeuvre sont disponibles dans une bibliothèques
void Library::add_Arts(const Book &arts) {
    this->Arts.push_back(arts);
}

// on ne rajoute pas plusieurs fois le meme auteur -> évite les doublons
int Library::add_Author(const Author &author) {
    int i = 0;
    while (i < this->Authors.size()) {
        if (this->Authors[i].getLastname().compare(author.getLastname()) ==
            0) { //on compare par le nom de famille si l'auteur existe déja
            if (this->Authors[i].getFirstname().compare(author.getFirstname()) ==
                0) // si le nom existe on check si le prenom est different
                return 84; // error value magic number, le nom ET le prénom de l'auteur existe déja dans la liste des auteur
        }
        i++;
    }
    this->Authors.push_back(author);//lauteur est nouveau et est rajouté dans les références de la bibliothèque
    return 0; // code de sortie en cas de succes
}

// recherche auteur par nom
string Library::research_author(const string &book_name) const {
    size_t i = 0;
    while (i != this->Arts.size()) {
        if (this->Arts[i].getBookName().compare(book_name) == 0)
            return (this->Arts[i].getBookAuthor().getFirstname() + " " + this->Arts[i].getBookAuthor().getLastname());
        i++;
    }
    return "book not found";
}

vector<Book> Library::research_books(const string &author_name) const {
    size_t i = 0;
    vector<Book> list_book;
    while (i < this->Authors.size()) {
        string tmp = this->Authors[i].getFirstname() + " " + this->Authors[i].getLastname();
        if (tmp.compare(author_name) == 0)
            break;
        i++;
    }
    // on check si la bibliothèque possède des oeuvres sur l'auteur donné
    if (i == this->Authors.size()) {
        Book tmp = Book("[No Books]", Author("[No Author]", "[No Author]"));
        list_book.push_back(tmp);
        return list_book;
    }
    // on récupère les oeuvres de l'auteur donné si il existe
    i = 0;
    while (i != this->Arts.size()) {
        string tmp = this->Arts[i].getBookAuthor().getFirstname() + " " + this->Arts[i].getBookAuthor().getLastname();
        if (tmp.compare(author_name) == 0)
            list_book.push_back(this->Arts[i]);
        i++;
    }
    return list_book;
}
