#include<iostream>
#include<vector>
using namespace std;

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
	struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
	int peekNum;
	bool peeked;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
		// Initialize any member here.
		// **DO NOT** save a copy of nums and manipulate it directly.
		// You should only use the Iterator interface methods.
		this->peeked = false;
	}

	// Returns the next element in the iteration without advancing the iterator.
	int peek() {
		if (hasNext()) {
			if (!peeked) {
				peekNum = Iterator::next();
				peeked = true;
			}
		}
		return peekNum;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
		if (!peeked) {
			return Iterator::next();
		}
		else {
			peeked = false;
			int tmp = peekNum;
			return tmp;
		}
	}

	bool hasNext() const {
		if(!peeked) return Iterator::hasNext();
		return true;
	}
};

Iterator::Iterator(const vector<int>& nums)
{
}

Iterator::Iterator(const Iterator & iter)
{
}

Iterator::~Iterator()
{
}

int Iterator::next()
{
	return 0;
}

bool Iterator::hasNext() const
{
	return false;
}
