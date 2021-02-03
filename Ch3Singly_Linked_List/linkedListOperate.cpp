#include "intSLList.h"

int main() {
    IntSLList list;
    for (int i = 0; i < 10; i++) {
      list.addToTail(i);    
    }
    list.Print();
    return 0;
}