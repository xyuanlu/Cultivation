/*
 * 380. Insert Delete GetRandom O(1)
 * 
 * Design a data structure that supports all following operations in average O(1) time.
 *
 * insert(val): Inserts an item val to the set if not already present.
 * remove(val): Removes an item val from the set if present.
 * getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
 */

class RandomizedSet {
public:
    
    // vector for all keys
    // unordered_map for <keys -> location in vector>
    // When deleting, swap the last one and the deleted one
    
    
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (_m.find(val) != _m.end())
            return false;
        _v.push_back(val);
        _m[val] = _v.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (_m.find(val) == _m.end())
            return false;
        
        int idx = _m[val];
        int end = _v.size()-1;
        _m[_v[end]] = idx;
        _v[idx] = _v[end];
        _v.pop_back();
        _m.erase(val);
        cout<<"after r "<<_v.size()<<" "<<_v[0]<<endl;
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        // retuens an int from [0, size()-1]
        return _v[rand() % _m.size()];
    }

private:
    vector<int> _v;
    // key -> location in the vector
    unordered_map<int, int> _m;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
