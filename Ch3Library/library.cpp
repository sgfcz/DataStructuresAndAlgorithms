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
private:
		char* title;
		Patron* patron;
		ostream& printBook(ostream&) const;
		friend ostream& operator<< (ostream out, const Book& bk) {
				return bk.printBook(out);
		}
		friend class CheckedOutBook;
		friend Patron;

};

class Patron {
public:
		Patron() {
		}
private:

};