#pragma once
const int maxLevel = 4;

template<class T>
class SkipListNode {
public:
		SkipListNode() {
		}
		T key;
		SkipListNode** next;
};
