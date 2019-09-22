/*
 * 146. LRU Cache
 */
 
 class LRUCache {
public:
    class Node{
    public:
         // We need the key to know when deleting a node, witch entry should be deleted form map.
        int val, key;   
        // Double linked list to find prev element 
        Node *next, *prev;
        
        Node(int v, int k, Node *n, Node *p): val(v), key(k), next(n), prev(p) {};
        
    };
    
    int size;
    int cap;
    map<int, Node*> m;
    Node* head;   // head->next is the most recent used elem
    
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        head = new Node(-1, -1, nullptr, nullptr);
    }
    
    int get(int key) {
        //cout<<"try To get "<<key<<endl;
        if (m.find(key) == m.end()) {
            return -1;
        }
        // move node to begin;
        MoveToBegin(m[key]);
        cout<<"found "<<m[key]->val<<endl;
        return m[key]->val;
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            m[key]->val =  value;
            MoveToBegin(m[key]);
            return;
        }
        if (size==cap) 
            RemoveLast();
        Node *next = head->next;
        Node *nNode = new Node(value, key, next, head);
        head->next = nNode;
        if(next != nullptr)
            next->prev = nNode;
        m[key] = nNode;
        size++;
        cout<<"size"<<size<<endl;
    }
    
    void RemoveLast() {
        Node *cur = head;
        while(cur->next->next != nullptr) {
            cur = cur->next;
        }
        Node *temp = cur->next;
        if(temp != nullptr) {
            cur->next = nullptr;
            //cout<<cur->val<<" erase "<<temp->val<<endl;
            m.erase(temp->key);
            delete temp;
            size--;
        }
    }
    
    void MoveToBegin(Node* n) {
        if (n->prev == head)
            return;
        Node *next = n->next;
        Node *prev = n->prev;
        Node *headNext = head->next;
        head->next = n;
        n->prev = head;
        n->next = headNext;
        if(headNext!= nullptr) {
            headNext->prev = n;
        }
        prev->next = next;
        if(next!=nullptr) {
            next->prev = prev;
        }
        //cout<<"begin "<<head->next->val<<endl;
    }
    
    ~LRUCache() {
        Node *cur = head;
        while(cur!=nullptr) {
            Node *next = cur->next;
            delete cur;
            cur = next;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
