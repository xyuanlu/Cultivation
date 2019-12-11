/*
 * 1206. Design Skiplist
 */
 
class Skiplist {
public:
    class P{
    public:
        P *up, *low, *l, *r;
        int val;
        
        P(int n) {
            up = nullptr;
            low = nullptr;
            l = nullptr;
            r = nullptr;
            val = n;
        }
    };
    
    Skiplist() {
        head = new P(INT_MIN);
        head->r = new P(INT_MAX);
        head->r->l = head;
        end = head->r;
    }
    
    // return the cloest number in lowest level
    P* findNode(int target, bool er) {
        P* res = nullptr;
        P* cur = head;
        while(cur!=nullptr) {
            //cout<<cur->val<<endl;
            if (cur->val == target) {
                if (er)
                    return cur;
                res = cur;
                //cout<<"Move down "<<cur->val<<endl;
                cur = cur->low;
                //cout<<"lower "<<(cur==nullptr)<<endl;
                continue;
            }
            if (cur->val<target) {
                if (cur->r->val <= target) {
                    //cout<<"Move right "<<cur->r->val<<endl;
                    cur = cur->r;
                    continue;
                } else {
                    res = cur;
                    cur=cur->low;
                }
            } else {
                return res;
            }
        }
        return res;
        
    }
    
    bool search(int target) {
        P* res = findNode(target, true);
        //cout<<"search "<<target<<" found "<<res->val<<endl;
        return res->val == target;
    }
    
    void add(int num) {
        //cout<<"a"<<endl;
        P* cur = findNode(num, false);
        // insert a node betwee cur and cur->r;
        P* prevAdded = nullptr;
        while (cur!= nullptr) {
            //cout<<"adding: "<<num<<endl;
            P* newNode = new P(num);
            P* next = cur->r;
            cur->r = newNode;
            newNode->l = cur;
            newNode->r = next;
            next->l = newNode;
            if (prevAdded!=nullptr) {
                prevAdded->up = newNode;
                newNode->low = prevAdded;
            }
            prevAdded = newNode;
            int a = rand() % 2;
            if (a==1) {
                while(cur->l!=nullptr && cur->up == nullptr)
                    cur = cur->l;
                if (cur->up == nullptr) {
                    // create a new layer
                    //cout<<"adding a new layer "<<cur->val<<endl;
                    cur->up = new P(INT_MIN);
                    cur->up->low = cur;
                    cur->up->r = new P(INT_MAX);
                    cur->up->r->l = cur->up;
                    cur->up->r->low = end;
                    end->up = cur->up->r;
                    head = cur->up;
                    end = head->r;
                }
                cur = cur->up;
            } else {
                cur = nullptr;
            }
        }
        
    }
    
    bool erase(int target) {
        //cout<<"e"<<endl;
        P* cur = findNode(target, false);
        if (cur->val != target) return false;
        //cout<<"found "<<cur->val<<endl;
        while (cur != nullptr) {
            //cout<<cur->val<<endl;
            P* prev = cur->l;
            P* next = cur->r;
            P* t = cur->up;
            //cout<<"deleting "<<cur->val<<endl;
            //cout<<"up level "<<(t!=nullptr)<<endl;
            delete cur;
            prev->r = next;
            next->l = prev;
            cur = t;
        }
        return true;
    }
    
    ~Skiplist(){
        vector<P*> temp;
        P* cur = head;
        while(cur!=nullptr) {
            temp.push_back(cur);
            cur = cur->low;
        }
        for(P* t:temp) {
            while(t!=nullptr) {
                P* n = t->r;
                //cout<<"deleting "<<t->val<<endl; 
                delete t;
                t = n;
            }
        }
    }
    
private:
    P *head, *end;
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
