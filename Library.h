#ifndef LIBRARY
#define LIBRARY
#include "book.h"
#include <initializer_list>
class Library : public Book   
{
	std::size_t books_number;
	Book* books;
	friend std::ostream& operator<<(std::ostream& ostr, const Library& L);
public:
	Library();
	Library(std::size_t);
	Library(std::initializer_list<Book> list);
	Library(const Library& orig);
	Library(Library&& orig);
	Library& operator=(const Library& right);
	Library& operator=(Library&& right);
	Book& operator[](std::size_t index);
	const Book& operator[](std::size_t index) const;
	std::size_t GetSize() const;
	~Library();
};
std::ostream& operator<<(std::ostream& ostr, const Library& L);

#endif











