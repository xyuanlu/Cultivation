/*
 * 1312. Minimum Insertion Steps to Make a String Palindrome
 * Given a string s. In one step you can insert any character at any index of the string.
 * Return the minimum number of steps to make s palindrome.
 * A Palindrome String is one that reads the same backward as well as forward.
 */
 
 class Solution {
public:
     // min number of insert to make [i, j] palindrome
    vector<vector<int>> m;
    int minInsertions(string s) {
       
        m = vector<vector<int>>(s.size(), vector<int>(s.size(), -1));
        
        helper(s, 0, s.size()-1);
        
        /*for(int i=0; i<s.size(); ++i) {
            for(int j=0; j<s.size(); ++j)
                cout<<m[i][j]<<" ";
            cout<<endl;
        }*/
        return m[0][s.size()-1];
    }
    
    int helper(string &s, int i, int j) {
        if (i>j) return INT_MAX;
        
        if (m[i][j] != -1)
            return m[i][j];
        int res = 0;
        if (i!=j) {
            if (s[j] != s[i]) {
                res = min (helper(s, i+1, j), helper(s, i, j-1)) +1;
            } else {
                if (j==i+1) {
                    res = 0;
                }
                else
                    res = helper(s, i+1, j-1);
            }
        } 
        m[i][j] = res;
        return res;
    }
};
