#include "leetcode.hpp"

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
	PeekingIterator(const vector<int>& nums)
        : Iterator(nums)
        , cur_iter_(nums.cbegin())
        , vec_end_(nums.cend()) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.

	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return *this->cur_iter_;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        return *this->cur_iter_++;
	}

	bool hasNext() const {
        return this->cur_iter_ != this->vec_end_;
	}

private:
    vector<int>::const_iterator cur_iter_;
    vector<int>::const_iterator vec_end_;
};
