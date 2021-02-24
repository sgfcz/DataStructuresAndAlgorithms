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
    friend ostream& operator<< (ostream out, const Book& bk) {
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
        return strcmp(name, ar.name) == 0;
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
    CheckedOutBook(list<Author>::iterator ar,
        list<Book>::iterator bk) {
        author = ar;
        book = bk;
    }

    bool operator== (const CheckedOutBook& bk) const {
        return strcmp(author->name, bk.author->name) == 0 &&
            strcmp(book->title, bk.book->title) == 0;
    }
private:
    list<Author>::iterator author;
    list<Book>::iterator book;
    friend void checkOutBook();
    friend void returnBook();
    friend Patron;
};

class Patron {
public:
    Patron() {
    }
private:
    char* name;
    list<CheckedOutBook> books;
    ostream& printPatron(ostream&) const;
    friend ostream& operator<< (ostream& out, const Patron& pn) {
        return pn.printPatron(out);
    }
    friend void checkOutBook();
    friend void returnBook();
    friend Book;
};

list<Author> catalog['Z' + 1];
list<Patron> people['Z' + 1];

ostream& Author::printAuthor(ostream& out) const {
    out << name << endl;
    list<Book>::const_iterator ref = books.begin();
    for ( ; ref != books.end(); ref++)
        out << *ref; // overloaded <<
	return out;
}

ostream& Book::printBook(ostream& out) const {
    out << " * " << title;
    if (patron != 0)
        out << " - checked out to" << patron->name; //overloaded<<
    out << endl;
    return out;
}

template<class T>
ostream& operator<< (ostream& out, const list<T>& lst) {
    for (list<T>::const_iterator ref = lst.begin(); ref != lst.end(); ref++)
        out << *ref; //overloaded<<
    return out;
}