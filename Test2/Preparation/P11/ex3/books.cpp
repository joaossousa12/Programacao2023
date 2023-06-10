#include "Book.h"
#include <iostream>
#include <sstream>

using namespace std;

void Book::build_index(const set<string>& words){
    size_t l = 1;
    for(auto page : book_){
        for(size_t i = 0; i < page.get_num_lines(); i++){
            string tmp, line = page.get_line(i);
            istringstream iss(line);
            while(iss >> tmp){
                for(auto word : words){
                    if(word == tmp) index_[tmp].insert(l);
                }
            }
        }
        l++;
    }
}

int main(){
    { Book b;
    if (!(b.import("book_01.txt"))) cout << "book not found! \n";
    set<string> words = { "C++", "linux", "computer" };
    b.build_index(words);
    b.show_index(); }
    /// C++: 1 / linux: 1 /
    { Book b;
    if (!(b.import("book_02.txt"))) cout << "book not found! \n";
    set<string> words = { "C++", "program", "computer", "windows" };
    b.build_index(words);
    b.show_index(); }
    /// C++: 1 2 3 / computer: 3 / program: 1 / windows: 1 3 /
    { Book b;
    if (!(b.import("book_03.txt"))) cout << "book not found! \n";
    set<string> words = { "linux", "program", "cpu" };
    b.build_index(words);
    b.show_index(); }
    /// cpu: 1 / linux: 2 / program: 2 /
    { Book b;
    if (!(b.import("book_04.txt"))) cout << "book not found! \n";
    set<string> words = { "computer", "program", "file","windows" };
    b.build_index(words);
    b.show_index(); }
    /// computer: 1 / file: 3 / program: 1 3 / windows: 3 /
    { Book b;
    if (!(b.import("book_05.txt"))) cout << "book not found! \n";
    set<string> words = { "linux", "byte", "cpu" };
    b.build_index(words);
    b.show_index(); }
    /// byte: 1 2 / cpu: 1 /
    return 0;
}