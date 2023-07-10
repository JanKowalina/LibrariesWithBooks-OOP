#include "book.h"


Book::Book() :
    author("not defined"), title("not defined") {}

Book::Book(const string& s1, const string& s2) : 
    author{ s1 }, title{ s2 } {}
          //constructor that accepts author and title in const l-reference version 

Book::Book(string&& s1, string&& s2) : 
    author{ std::move(s1) }, title{ std::move(s2) } {}
          //constructor that accepts author and title in const r-reference version

Book::Book(const Book& b) { //copy constructor
    author = b.author; 
    title = b.title; 
} 

Book::Book(Book&& move) { // move constructor
    author = std::move(move.author);                                                  
    title = std::move(move.title);                                                  
} 


void Book::SetAuthor(const string& A) {
    author = A;
}
void Book::SetTitle(const string& T) {
    title = T;
}
void Book::SetAuthor(string&& A) {
    author = A;
}
void Book::SetTitle(string&& T) {
    title = T;
}
string Book::GetAauthor(void) {
    return author;
}
string Book::GetTitle(void) {
    return title;
}

Book& Book::operator=(const Book& copy) { //copy assignment operator
    author = copy.author;
    title = copy.title;
    return *this;
}
Book& Book::operator=(Book&& move) { //move move assignment operator
    author = std::move(move.author);                                                  
    title = std::move(move.title);                                                   
    return *this;                                                                     
}

std::ostream& operator<<(std::ostream& ostr, const Book& b) {
    ostr << "Author: " << b.author << ", Title: " << b.title << endl;
    return ostr;
}