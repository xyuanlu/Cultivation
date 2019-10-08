/*
 * 642. Design Search Autocomplete System
 * 
 */
 
class AutocompleteSystem {
public:
    // Return all sentences with is prefix. 
    // Keep the top K
    class TrieNode{
    public:
        int count;   //count = 1 only when we isWord == true
        vector<TrieNode*> nodes;
        
        TrieNode() {
            nodes = vector<TrieNode*> (27, nullptr);  //including ' '.
            count = 0;
        }
        
        ~TrieNode() {
            for(int i=0; i<27; ++i) {
                if (nodes[i]!= nullptr)
                    delete nodes[i];
            }
        }
    };
    
    TrieNode *root, *cur;
    string str;
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();
        cur = root;
        for (int i=0; i<sentences.size(); ++i) {
            int time = times[i];
            TrieNode *t = root;
            // TODO space
            for(int j=0; j<sentences[i].size(); ++j) {
                int idx = 0;
                if (isalpha(sentences[i][j])) {
                    idx = sentences[i][j]-'a';
                } else {
                    idx = 26;
                }
                //cout<<"creating "<<sentences[i][j]<<" "<<idx<<endl;
                if (t->nodes[idx] == nullptr) {
                    t->nodes[idx] = new TrieNode();
                }
                t = t->nodes[idx];
            }
            t->count = times[i];
        }
        
    }
    
    vector<string> input(char c) {
        //cout<<"input "<<c<<endl;
        vector<string> res;
        if (c == '#') {
            cur->count ++;
            //cout<<str<<" "<<cur->count<<endl;
            cur = root;
            str = "";
            return res;
        }
        str += c;
        if (isalpha(c) && cur->nodes[c-'a'] == nullptr) {
            cur->nodes[c-'a'] = new TrieNode();
            cur = cur->nodes[c-'a'];
            return res;
        } else if (c == ' ' && cur->nodes[26] == nullptr) {
            cur->nodes[26] = new TrieNode();
            cur = cur->nodes[26];
            return res;
        }
        
        if (isalpha(c)) {
            cur = cur->nodes[c-'a'];
        } else {
            cur = cur->nodes[26];
        }
        
        helper(cur, res, str);
        //cur = cur->nodes[c];
        return res;
    }
    
    ~AutocompleteSystem() {
        delete root;
    }
    
    struct OrderByCount {
        bool operator()(pair<int, string> const& p1, pair<int, string> const& p2) {
            if (p1.first == p2.first) {
                // If they have the same occurance, then compare the digits one by one.
                for (int i=0; i<min(p1.second.size(), p2.second.size()); ++i) {
                    if (p1.second[i] != p2.second[i]) {
                        //cout<<i<<" "<<p1.second[i]<<" "<<p2.second[i]<<endl;
                        return p1.second[i] > p2.second[i];
                    }
                }
                return p1.second.size() > p2.second.size();
            }
            return p1.first < p2.first;
        }
    };
    
    typedef priority_queue<pair<int, string>, vector<pair<int, string>>, OrderByCount> pq;
    void helper(TrieNode *cur, vector<string>& res, string s) {
        pq temp;

        dfs(cur, temp, s);
        
        while(!temp.empty()) {
            res.push_back(temp.top().second);
            temp.pop();
            if (res.size()==3)
                break;
        }
    }
    
    void dfs(TrieNode *cur, pq& temp, string s) {
        if (cur->count !=0) {
            //cout<<" push "<<s<<endl;
            temp.push(make_pair(cur->count, s));
        }
        
        for (int i=0; i<27; ++i) {
            if (cur->nodes[i]!= nullptr) {
                if (i==26) {
                    s+=" ";
                } else {
                    s+='a'+i; 
                }
                dfs(cur->nodes[i], temp, s);
                s.pop_back();
            }
        }
        
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
