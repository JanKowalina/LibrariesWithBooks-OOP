#include "Library.h"


int main()
{

    string a = "Henryk Sienkiewicz", t = "W pustyni i w puszczy";
    Book b;
    cout << "b: " << b << endl;
    Book b1 = { a, t }; // calling to constructor that accepts
                        // author and title in const l-reference version
    cout << "b1: " << b1 << endl;
    Book b2 = { "J.R.R Tolkien","Hobbit" };  // calling to constructor that accepts
                                    // author and title in const r-reference version
    cout << "b2: " << b2 << endl;
    Book b3 = std::move(b1);      // calling move constructor                                         
    cout << "b3: " << b3 << " b1: " << b1 << endl;

    b = std::move(b2);    //calling move move assignment operator                                                                
    cout << "b: " << b << " b2:" << b2 << endl;
    b.SetAuthor("Ferenc Molnar");
    cout << "b: " << b << endl;
    b.SetTitle("Chlopcy z placu broni");
    cout << "b: " << b << endl;

   Library e;
    cout << "e: " << e << endl;
    Library l1 = { {"Henryk Sienkiewicz", "W pustyni i w puszczy"},
    {"J.R.R Tolkien", "Hobbit"},
    {"Ferenc Molnar", "Chlopcy z placu broni"},
    {"J.R.R Tolkien", "Hobbit"},
    {"Ferenc Molnar", "Chlopcy z placu broni"} };
    cout << "l1: " << l1 << endl;
    Library l3 = l1;
    cout << "e: " << l3 << " l2: " << l1 << endl;
    Library l2(2);
    cout << "l2: " << l2 << endl;
    l2[0] = { "Boleslaw Prus", "Lalka" };
    l2[1] = { "Adam Mickiewicz", "Pan Tadeusz" };
    cout << "l2: " << l2 << endl;
    e = std::move(l2);
    cout << "e: " << e << " l2: " << l2 << endl;
    l1[0] = std::move(e[1]);
    cout << "l1: " << l1 << " e: " << e << endl;

    
    
    return 0;
}












