cmake_minimum_required(VERSION 3.21)
project(Bibliotheque)

set(CMAKE_CXX_STANDARD 20)

add_executable(Bibliotheque main.cpp Author.cpp AuthorView.cpp Library.cpp LibraryView.cpp Book.cpp BookView.cpp)
