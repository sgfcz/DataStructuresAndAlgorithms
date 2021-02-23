#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

class Person;

class Book {
public:
    Book() {
        patron = 0;
    }
    bool operator== (const Book& bk) const {
        return strcmp(title, bk.title) == 0;
    }
private:
    char* title;
    Patron* patron;
    ostream& printBook(ostream&) const;
    friend ostream& operator<< (ostream out, const Book& bk) { //ÖØÔØÔËËã·û<<
        return bk.printBook(out);
    }
    friend class CheckedOutBook;
    friend Patron;
    friend void includeBook();
    friend void checkOutBook();
    friend void returnBook();
};

class Author {
public:
    Author() {
    }
    bool operator== (const Author& ar) const { 
    }
private:
    char* name;
    list<Book> books;
    ostream& printAuthor(ostream&) const;
    friend ostream& operator<< (ostream& out, const Author& ar) {
        return ar.printAuthor(out);
    }
    friend void includeBook();
    friend void checkOutBook();
    friend void returnBook();
    friend class CheckedOutBook;
    friend Patron;
};

class CheckedOutBook {
public:
};

class Patron {
public:
    Patron() {
    }
private:

};