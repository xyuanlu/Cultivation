/*
 * 212. Word Search II
 * Given a 2D board and a list of words from the dictionary, find all words in the board.
 */
 
 class TrieNode {
public:
    vector<TrieNode*> node{vector<TrieNode*> (26, nullptr)};
    bool isWord = false;
    string word;
    ~ TrieNode(){
        for(auto it:node) {if(it) delete it;}
    }  
};


class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode root;
        for (string s:words) {
            TrieNode* cur = &root;
            for (char c:s) {
                TrieNode *next = cur->node[c-'a'];
                if (next == nullptr) {
                    next = new TrieNode();
                    cur->node[c-'a'] = next;
                }
                cur = next;
            }
            cur->word = s;
            cur->isWord = true;
        }
        
        /*We do DFS for each i, j in diagram
         * We continue to next step only if the element is in trie*/
        
        vector<string> res;
        for (int i=0; i<board.size(); ++i) {
            for(int j=0; j<board[0].size(); ++j) {
                helper(board, i, j, &root, res);
            }
        }
        return res;
    }
    
    void helper(vector<vector<char>>& board, int x, int y, TrieNode * root, vector<string>& res) {
        //cout<<x<<" "<<y<<endl;
        if (x<0 || y<0 || x>=board.size() || y>=board[0].size() || root == nullptr || board[x][y] == '*')
            return;
        TrieNode *cur = root->node[board[x][y]-'a'];
        if(cur == nullptr)
            return;
        if(cur->isWord) {
            res.push_back(cur->word);
            cur->isWord = false;
        }
        const char c = board[x][y];
        board[x][y] = '*';
        helper(board, x+1, y, cur, res);
        helper(board, x-1, y, cur, res);
        helper(board, x, y+1, cur, res);
        helper(board, x, y-1, cur, res);
        board[x][y] = c;
        
    }
};
