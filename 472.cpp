/*
 * 472. Concatenated Words
 * Given a list of words (without duplicates), please write a program that returns
 * all concatenated words in the given list of words.
 * A concatenated word is defined as a string that is comprised entirely of at least
 * two shorter words in the given array.
 */
 
class Solution {
public:
    class TrieNode {
    public:
        vector<TrieNode*> node;
        bool isWord;
        
        TrieNode() {
            isWord = false;
            node = vector<TrieNode*>(26, nullptr);
        }
        
        ~TrieNode() {
            for(int i=0; i<26; ++i) {
                delete node[i];
            }
        }
    };
    
    void AddWd (const string& s, TrieNode *root) {
        TrieNode *cur = root;
        for (int i=0; i<s.size(); ++i) {
            if (cur->node[s[i]-'a'] == nullptr) {
                cur->node[s[i]-'a'] = new TrieNode();
            }
            cur = cur->node[s[i]-'a'];
        }
        cur->isWord = true;
    }
    
    // return true if this s from idx can be broken into >=2 words
    bool helper(const string& s, int idx, int cur, map<int, bool>& m) {
        if(idx == s.size())
            return cur>=2;
        TrieNode *t = root;
        if (m.find(idx) != m.end())
            return m[idx];
        
        for (int i=idx; i<s.size(); ++i) {
            if (t->node[s[i]-'a'] == nullptr) {
                return false;
            }
            t = t->node[s[i]-'a'];
            if (t->isWord) {
                if(helper(s, i+1, cur+1, m))
                    return true;
            }
        }
        m[idx] = false;
        return false;
    }
    
    TrieNode* root;
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        // Trie + word break
        root = new TrieNode();
        vector<string> res;
        
        for (string& s:words) {
            AddWd(s, root);
        }
        
        for (string& s:words) {
            int cur = 0;
            map<int, bool> m;
            if (helper(s, 0, cur, m)) {
                res.push_back(s);
            }
        }
        
        return res;
    }
    
    ~Solution (){
        delete root;
    }
};
