#pragma once
#ifndef DLL_QUEUE
#define DLL_QUEUE

#include <list>

template<class T>
class Queue {
public:
		Queue() {
		}
		void clear() {
				lst.clear();
		}

private:
		std::list<T> lst;
};
#endif // !DLL_QUEUE
