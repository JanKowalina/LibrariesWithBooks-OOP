#include "Library.h"
#define DEFAULT_B_N 4 //B_N - book number

Library::Library() 
    : books_number{ DEFAULT_B_N }, books{new Book[DEFAULT_B_N]} {} 

Library::Library(std::size_t n)
    : books_number{ n }, books{ new Book[n] } {}

Library::Library(std::initializer_list<Book> list) 
    :books_number{list.size()}, books{new Book[list.size()]}
{
    std::size_t i = 0;
    for (Book v : list)
    {
        books[i] = std::move(v);
        i++;
    }

}
// copy constructor
Library::Library(const Library& orig) 
    : books_number(orig.books_number), books{new Book[orig.books_number]}
{
    for (std::size_t i = 0; i < books_number; i++)
        books[i] = orig.books[i];
}
//move constructor
Library::Library(Library&& orig) {
    books = orig.books;
    books_number = orig.books_number;
    orig.books = nullptr;
    orig.books_number = 0;
}
//copy assignment operator
Library& Library::operator=(const Library& right) {
    Library tmp = right;
    std::swap(books, tmp.books);
    std::swap(books_number, tmp.books_number);
    return *this;
}
//move move assignment operator
Library& Library::operator=(Library&& right) {
    books = right.books;
    books_number = right.books_number;
    right.books = nullptr;
    right.books_number = 0;
    return *this;
}
// a [] operator overloading
Book& Library::operator[](std::size_t index) {
    return books[index];
}
// const version of a [] operator overloading
const Book& Library::operator[](std::size_t index) const{
    return books[index];
}

std::size_t Library::GetSize() const{
    return books_number;
}

Library::~Library() {
    if (books != nullptr)
        delete[] books;
}
//std::ostream print operator << overloading of <<
std::ostream& operator<<(std::ostream& ostr, const Library& L) {
    ostr << "Library" << endl;
    for (std::size_t i = 0; i < L.books_number; i++) {
        ostr << "book " << i + 1 <<"   " << L.books[i];
    }
    return ostr;
}

















