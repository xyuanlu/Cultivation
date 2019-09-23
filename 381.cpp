/*
 * 381. Insert Delete GetRandom O(1) - Duplicates allowed
    
    Design a data structure that supports all following operations in average O(1) time.

      Note: Duplicate elements are allowed.
      insert(val): Inserts an item val to the collection.
      remove(val): Removes an item val from the collection if present.
      getRandom: Returns a random element from current collection of elements.
      The probability of each element being returned is linearly related to the number of same value the collection contains.
 */
 
 class RandomizedCollection {
public:
    /*
     * Datastructure design.
     * vector<int> to store all item. Swap when deleting.
     * Unordered_map to track the idx of each value.
     */
    
    unordered_map<int, unordered_set<int>> m;
    vector<int> v;
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        v.push_back(val);
        m[val].insert(v.size()-1);
        /*cout<<"insert ";
        for(auto i:v) {
            cout<<i<<" ";
        }
        cout<<endl;*/
        return m[val].size()==1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(m.find(val) == m.end())
            return false;
        int t = v[v.size()-1];
        int idx = *(m[val].begin());
        //cout<<t<<" "<<idx<<" ";
        v[idx] = t;
        m[val].erase(idx);
        m[t].insert(idx);
        m[t].erase(v.size()-1);
        v.pop_back();
        if(m[val].size() ==0)
            m.erase(val);
        /*cout<<"remove ";
        for(auto i:v) {
            cout<<i<<" ";
        }
        cout<<endl;*/
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        /*for(auto i:v) {
            cout<<i<<" ";
        }
        cout<<endl;*/
        int idx = rand() %(v.size());
        return v[idx];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
