/*
 * 208. Implement Trie (Prefix Tree)
 * Implement a trie with insert, search, and startsWith methods.
 */
 
class Trie {
public:
    class TrieNode{
    public:
        bool isW;
        vector<TrieNode*> next;
        
        TrieNode(){
            isW = false;
            next = vector<TrieNode*>(26, nullptr);
        }
        
        ~TrieNode(){
            for(TrieNode* t:next) {
                if (t) delete t;
            }
        }
    };
    
    
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *cur = root;
        for(char c:word) {
            if (cur->next[c-'a'] == nullptr) {
                cur->next[c-'a'] = new TrieNode();
            }
            cur = cur->next[c-'a'];
        }
        cur->isW = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *cur = find(word);
        return cur!=nullptr && cur->isW == true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *cur = find(prefix);
        return cur!=nullptr;
    }
    
    ~Trie(){
        delete root;
    }
    
private:
    TrieNode *root;
    
    TrieNode* find(string& word){
        TrieNode *cur = root;
        for(char c:word) {
            if (cur->next[c-'a'] == nullptr) {
                return nullptr;
            }
            cur = cur->next[c-'a'];
        }
        return cur;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
