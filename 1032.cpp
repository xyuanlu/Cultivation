/*
 * 1032. Stream of Characters
 */
 
class StreamChecker {
public:
    class TrieNode {
    public:
        vector<TrieNode*> nodes;
        bool isWord;
        
        TrieNode(){
            for(int i=0; i<26; ++i) {
                nodes.push_back(nullptr);
            }
            isWord = false;
        }
        
        ~TrieNode() {
            for(int i=0; i<26; ++i) {
                if (nodes[i] == nullptr)
                    delete nodes[i];
            }    
        }
        
        
    };
    
    void AddWord(string& s) {
        //cout<<s<<endl;
        TrieNode *cur = root;
        for(int i=0; i<s.size(); ++i) {
            if (cur->nodes[s[i]-'a'] == nullptr) {
                cur->nodes[s[i]-'a'] = new TrieNode();
            }
            cur = cur->nodes[s[i]-'a'];
        }
        cur->isWord = true;
    }
    
    TrieNode *root;
    queue<TrieNode*> m;
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        
        for(int i=0; i<words.size(); ++i) {
            AddWord(words[i]);
        }
    }
    
    bool query(char letter) {
        //cout<<"qq "<<letter<<endl;
        queue<TrieNode*> n;
        bool res = false;
        
        while(!m.empty()) {
            TrieNode *t = m.front();
            m.pop();
            if (t->nodes[letter-'a'] != nullptr) {
                n.push(t->nodes[letter-'a']);
                if (t->nodes[letter-'a']->isWord)
                    res = true;
            }
        }
        
        if (root->nodes[letter-'a'] != nullptr) {
            n.push(root->nodes[letter-'a']);
            //cout<<"letter: " <<letter<<" "<<(root->nodes[letter-'a']->isWord)<<endl;
            if (root->nodes[letter-'a']->isWord) {
                res = true;
            }
        }
        m=n;
        return res;
    }
    
    ~StreamChecker(){
        delete root;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
