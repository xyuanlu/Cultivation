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
