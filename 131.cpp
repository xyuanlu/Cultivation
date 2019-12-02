/*
 * 131. Palindrome Partitioning
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 *
 * Return all possible palindrome partitioning of s.
 */
 
class Solution {
public:
    /* similar: word break 1, 2*/
    vector<vector<string>> partition(string s) {
        // [i, j] is palindrome
        vector<vector<int>> m(s.size(), vector<int>(s.size(), false));
        for(int i=s.size()-1; i>=0; --i) {
            for(int j=i; j<s.size(); ++j) {
                if (s[i] == s[j]) {
                    if (j<=i+2) {
                        m[i][j] = true;
                    } else {
                        m[i][j] = m[i+1][j-1];
                    }
                }
            }
        }
        
        vector<vector<string>> res;
        vector<string> cur;
        int idx = 0;
        //vector<int> c(s.size(), true);      // <<<<-------- This is not needed, since we can always reach the end
        helper(s, m, res, cur, idx);
        return res;
    }
    
    void helper(string& S, vector<vector<int>>& m,
                vector<vector<string>>& res, vector<string>& cur,
                int idx) {
        
        if (idx == S.size()) {
            res.push_back({cur});
            return;
        }
       // cout<<idx<<endl;
        int ress = false;
        for(int j=idx; j<S.size(); ++j) {
            if(m[idx][j]) {
                //cout<<idx<<" "<<j<<endl;
                cur.push_back(S.substr(idx, (j-idx+1)));
                helper(S, m, res, cur, j+1);
                cur.pop_back();
            }                
        }
        //cout<<"cc"<<endl;
        //c[idx] = ress;
        return;              
                        
    }
};
