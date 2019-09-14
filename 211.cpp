/*
 * 211. Add and Search Word - Data structure design
 * Design a data structure that supports the following two operations:
 *
 * void addWord(word)
 * bool search(word)
 * search(word) can search a literal word or a regular expression string containing only
 * letters a-z or .. A . means it can represent any one letter.
 */
class WordDictionary {
    /*
     * DFS in a trie tree.
     */
    class TrieNode{
    public:
        bool isWord;
        vector<TrieNode*> next;
        
        TrieNode(){
            isWord = false;
            for(int i=0; i<26; ++i) {
                next.push_back(nullptr);
            }
        }
        
        ~TrieNode(){
            for (int i=0; i<26; ++i) {
                if (next[i] != nullptr) {
                    delete next[i];
                }
            }
        }
        
        
        void InsertWord(const string& s) {
            TrieNode *cur = this;
            for (int i=0; i<s.size(); ++i) {
                if (cur->next[s[i]-'a'] == nullptr) {
                    cur->next[s[i]-'a'] = new TrieNode();
                }
                cur = cur->next[s[i]-'a'];
            }
            cur->isWord = true;
        }
        
    };
public:
    /** Initialize your data structure here. */
    std::unique_ptr<TrieNode> tn;
    WordDictionary() {
        tn = make_unique<TrieNode>();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        //cout<<"add "<<word<<endl;
        tn->InsertWord(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return helper(word, 0, tn.get());
    }
    
    bool helper(const string& word, int idx, TrieNode* root) {
        //cout<<word<<" "<<idx<<endl;
        if (root == nullptr)
            return false;
        if (idx == word.size())
            return root->isWord;
        if(word[idx] != '.') 
            return helper(word, idx+1, root->next[word[idx]-'a']);
        //bool found = false;
        for (int i=0; i<26; ++i) {
            if (root->next[i] == nullptr)
                continue;
            if (helper(word, idx+1, root->next[i]))
                return true;
        }
            return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
