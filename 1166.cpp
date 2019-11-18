/*
 * 1166. Design File System
 */
 
class FileSystem {
public:
    class Node{
    public:
        unordered_map<string, Node*> next;
        int v;
        
        Node(int vv) {v = vv;}
        
        ~Node(){
            for(auto &it:next) {
                delete it.second;
            }
        }
    };
    
    Node* root;
    FileSystem() {
        root = new Node(-1);
    }
    
    bool createPath(string path, int value) {
        Node* cur = root;
        vector<string> p;
        helper(p, path);
        //for(auto it:p) {cout<<it<<" ";} cout<<endl; 
        for(int i=0; i<p.size(); ++i) {
            if (cur->next.find(p[i]) == cur->next.end()) {
                if (i!=p.size()-1)
                    return false;
                cur->next[p[i]] = new Node(value);
                return true;
            }
            cur = cur->next[p[i]];
        }
        return false;
    }
    
    int get(string path) {
        Node* cur = root;
        vector<string> p;
        helper(p, path);
        //for(auto it:p) {cout<<it<<" ";} cout<<endl; 
        for(int i=0; i<p.size(); ++i) {
            if (cur->next.find(p[i]) == cur->next.end()) {
                return -1;
            }
            //cout<<(cur->v)<<endl;
            cur = cur->next[p[i]];
        }
        return cur->v;
    }
    
    void helper(vector<string>& res, string& s) {
        int prev = 0;
        for(int i=1; i<s.size(); ++i) {
            if (s[i] == '/') {
                res.push_back(s.substr(prev+1, i-prev-1));
                prev = i;
            }
        }
        res.push_back(s.substr(prev+1, s.size()-prev-1));
    }
        
        
        
    ~FileSystem(){
        delete root;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */
