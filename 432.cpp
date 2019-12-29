/*
 * 432. All O`one Data Structure
 * Implement a data structure supporting the following operations:
 *
 * Inc(Key) - Inserts a new key with value 1. Or increments an existing key by 1. Key is guaranteed to be a non-empty string.
 * Dec(Key) - If Key's value is 1, remove it from the data structure. Otherwise decrements an existing key by 1. If the key does not exist, this function does nothing. Key is guaranteed to be a non-empty string.
 * GetMaxKey() - Returns one of the keys with maximal value. If no element exists, return an empty string "".
 * GetMinKey() - Returns one of the keys with minimal value. If no element exists, return an empty string "".
 * Challenge: Perform all these in O(1) time complexity.
 */
 

class AllOne {
    /*
      list:
      [ 1 ] <-> [ 2 ] <-> [ 3 ]
      [ a, b]   [c]       [d]
           ^
           |----
      map: |   |
      [a ]     ----[b]     [c]  [d]  ... 
      [ptr to 
      'a' in list]
    
    */
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (_m.find(key) == _m.end()) { 
            // new elem
            if (_list.size()==0 || _list.front().value!=1) {
                _list.push_front({1, {key}}); 
            } else {
                _list.front().keys.insert(key);
            }
            _m[key] = _list.begin();            
        } else {
            // inc existing elem
            auto it = _m[key];
            int cur = it->value;
            auto it2 = it; 
            std::advance(it2, 1);
            it->keys.erase(key);
            // if count==0 erase
            if (it->keys.size()==0) {
                it2 = _list.erase(it);
            }
            // add in the next node
            if (it2!=_list.end() && it2->value == cur+1) {
                it2->keys.insert(key);
                _m[key] =it2;
            } else {
                //add new node
                auto it3 = _list.insert(it2, {cur+1, {key}});
                _m[key] =it3;
            }
            
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (_m.find(key) == _m.end())
            return;
        
        auto it = _m[key];
        int cur = it->value;
        it->keys.erase(key);
        if (it->keys.size()==0) {
            it = _list.erase(it);
        }
        if (cur==1) {
            _m.erase(key);
            //cout<<"VVV"<<endl;
            return;
        }
            
        // add in the prev node
        if (it!=_list.begin()) {
            auto it2 = it;
            it2--;
            if (it2->value == cur-1) {
                it2->keys.insert(key);
                _m[key] =it2;
                //cout<<"VV"<<endl;
                return;
            }
        }
        //add new node
        auto it3 = _list.insert(it, {cur-1, {key}});
        cout<<it3->value<<endl;
        _m[key] = it3;
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (_list.size()==0) return "";
        else {
            //cout<<"max "<<_list.back().value<<endl;
            return *(_list.back().keys.begin());
        }
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (_list.size()==0) return "";
        else {
            //cout<<"min "<<_list.front().value<<endl;
            return *(_list.front().keys.begin());
        }
    }
    
    class Node{
    public:
        int value;
        unordered_set<string> keys;
    };
    
private:
    std::list<Node> _list;
    unordered_map<string, list<Node>::iterator> _m;
    
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */



// Map is not O(1)
class AllOneNotReally {
public:
    unordered_map<string, int> kv;
    map<int, unordered_set<string>> vk;
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        kv[key] ++;
        int v = kv[key];
        if (v>1) {
            vk[v-1].erase(key);
            if (vk[v-1].size()==0)
                vk.erase(v-1);
        }
        vk[v].insert(key);
        //cout<<key<<" "<<v<<endl;
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (kv.find(key) == kv.end()) 
            return;
        kv[key] --;
        int v = kv[key]; 
        if (v==0)
            kv.erase(key);
        vk[v+1].erase(key);
        if (vk[v+1].size()==0)
                vk.erase(v+1);
        if (v>0) {
            vk[v].insert(key);
        }
        //cout<<key<<" "<<v<<endl;
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (kv.size()==0)
            return "";
        auto it = vk.rbegin();
        //cout<<it->first<<endl;
        return *(it->second.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (kv.size()==0)
            return "";
        //cout<<it->first<<" "<<it->second.size()<<endl;
        return *(vk.begin()->second.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
