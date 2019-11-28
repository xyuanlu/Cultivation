/*
 * 284. Peeking Iterator
 */
 
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
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    _cur = -1;
        _peeked = false;
        
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if (_peeked) {
            return _cur;
        }
        _peeked = true;
        _cur = Iterator::next();
        return _cur;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if (_peeked) {
            _peeked = false;
            return _cur;
        }
        return Iterator::next();
	}

	bool hasNext() const {
	    if (_peeked) {
            return true;
        }
        else 
            return Iterator::hasNext();
	}
private:
    int _cur;
    bool _peeked;
};
