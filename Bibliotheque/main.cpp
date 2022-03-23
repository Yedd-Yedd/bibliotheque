#include <iostream>
#include "Library.h"
#include "LibraryView.h"

// ON REMPLIS LA LIBRAIRIE POUR DU TEST
void fill_lib(Library* lib){
    Author my_author = Author("arthur", "jean");
    Author my_author2 = Author("test", "t");
    Book my_book = Book("lolilol", my_author);
    Book my_book2 = Book("ly", my_author2);
    Book my_book3 = Book("je test", my_author2);

    lib->add_Author(my_author);
    lib->add_Author(my_author2);
    lib->add_Arts(my_book);
    lib->add_Arts(my_book2);
    lib->add_Arts(my_book3);
}

void consultAuthor(LibraryView *lib, Library *curr_lib){
    char tmp[64];
    cout << "un nom de livre et je vous indiquerais son auteur" << endl;
    scanf("%[^\n]",&tmp);
    lib->show_search_result_author(curr_lib, string(tmp));
    fflush(stdin);
}

void consultBook(LibraryView *lib, Library *curr_lib){
    char tmp[64];
    cout << "Un nom d'auteur et je vous donne la liste de ses livres" << endl;
    scanf("%[^\n]",&tmp);
    lib->show_search_result_books(curr_lib, string(tmp));
    fflush(stdin);
}

void addBook(Library *lib){
    char tmp[64];
    cout << "un depot de livre ? entrez le nom du livre" << endl;
    scanf("%[^\n]",&tmp);
    string book_name = string(tmp);
    fflush(stdin);
    cout << "entrez le nom et prenom de l'auteur" << endl;
    scanf("%[^\n]",&tmp);
    string autor_name = string(tmp);
    fflush(stdin);
    string prenom = autor_name.substr(0, autor_name.find(" "));
    string nom = autor_name.substr(autor_name.find(" ") + 1, autor_name.size());
    Author new_author = Author(prenom, nom);

    Book new_book = Book(book_name, new_author);
    lib->add_Arts(new_book);
    lib->add_Author(new_author);
}

int exec(){
    int state = 0;
    Library *my_lib = new Library();
    LibraryView *libview = new LibraryView();
    fill_lib(my_lib);
    cout << "Bienvenue a la Grande Bibliotheque de Babylone" << endl;
    cout << "voici toute la liste de ce qui est contenu" << endl;
    libview->show_arts(my_lib);
    while (state == 0){
        cout << "-------------------------" << endl
        << "que voulez-vous faire? :" << endl
        << "1 Consulter un livre" << endl
        << "2 Consulter un auteur" << endl
        << "3 Ajouter une oeuvre" << endl
        << "4 Quitter" << endl;
        cout << ">";
        int req = 0;
        scanf("%d", &req);
        fflush(stdin);
        switch(req){
            default:
                cout << "je n'ai pas compris votre demande" << endl;
                break;
            case 1:
                consultAuthor(libview, my_lib);
                break;
            case 2:
                consultBook(libview, my_lib);
                break;
            case 3:
                addBook(my_lib);
                break;
            case 4:
                state++;
                break;
        }
    }
    return 0;
}

int main() {
    exec();
    return 0;
}
