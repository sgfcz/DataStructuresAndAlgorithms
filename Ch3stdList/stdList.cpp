#include <iostream>
#include <list>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
		list<int> lst1;			  //lst1 is empty
		list<int> lst2(3, 7); //lst2 = (7 7 7)
		for (int j = 1; j <= 5; j++) { //lst1 = (1 2 3 4 5)
				lst1.push_back(j);
		}
		list<int>::iterator i1 = lst1.begin(), i2 = i1, i3;
		i2++; i2++; i2++;
		list<int> lst3(++i1, i2);

		return 0;
}