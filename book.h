#ifndef BOOK
#define BOOK
#include <iostream>
#include <string>
using namespace std;
class Book {
    std::string author, title;
    friend std::ostream& operator<<(std::ostream&, const Book&);
public:
    Book();
    Book(const string& s1, const string& s2);
    Book(string&& s1, string&& s2);
    Book(const Book& b);
    Book(Book&& move);
    void SetAuthor(const string& A);
    void SetTitle(const string& T);
    void SetAuthor(string&& A);
    void SetTitle(string&& T);
    string GetAauthor(void);
    string GetTitle(void);
    Book& operator=(const Book& copy);
    Book& operator=(Book&& move);
};
std::ostream& operator<<(std::ostream& ostr, const Book& b);

#endif 

















