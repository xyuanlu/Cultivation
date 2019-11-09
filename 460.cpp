/*
* 460. LFU Cache
* 
* Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following
* operations: get and put.
*
* get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
* put(key, value) - Set or insert the value if the key is not already present. When the cache reaches its
* capacity, it should invalidate the least frequently used item before inserting a new item. For the purpose
* of this problem, when there is a tie (i.e., two or more keys that have the same frequency), the least recently
* used key would be evicted.
*
* Note that the number of times an item is used is the number of calls to the get and put functions for that
* item since it was inserted. This number is set to zero when the item is removed.
*/


class LFUCache {
public:
    class Node{
    public:
        int k, v, f, t;
        
        //Node(int kk, int vv, int ff, int tt) : k(kk), v(vv), f(ff), t(tt) {};
        
        bool operator<(const Node& n) const{
            if (f==n.f)
                return t<n.t;
            else {
                return f<n.f;
            }
        }
        
    };
    
    LFUCache(int capacity) {
        cap = capacity;
        _t = 0;
    }
    
    int get(int key) {
       // cout<<"g "<<key<<endl;
        auto it = m.find(key);
        if (it == m.end()) return -1;
        n.erase(it->second);
        touch(it->second);
        return it->second.v;
    }
    
    void put(int key, int value) {
        //cout<<"p "<<key<<" "<<m.size()<<endl;
        if (m.find(key) != m.end()) {
            Node temp = m[key];
            n.erase(temp);
            m[key].v = value;
            touch(m[key]);
            return;
        }
        Node nn{key, value, 1, ++_t};
        if (m.size() == cap && !m.empty()) {
            // remove one element
            auto it = n.begin();
            int kk = it->k;
            m.erase(kk);
            //cout<<"erase "<<kk<<endl;
            n.erase(n.begin());
        }
        if (m.size() < cap) {
            m[key] = nn;
            //cout<<key<<endl;
            n.insert(nn);
        }
        
    }
    
private:
    void touch(Node &nn) {
        _t++;
        //n.erase(nn);
        nn.f++;
        nn.t = _t;
        n.insert(nn);
        
    }
    
    unordered_map<int, Node> m; // key to  Node
    set<Node> n;                 // Set of node, ordered first by frequency then t
    int cap;
    int _t;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
