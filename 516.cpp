/*
* 516. Longest Palindromic Subsequence
*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int res = 0;
        // m[i][j] is the Longest PS, no need to include s[i] and s[j]
        vector<vector<int>> m(s.size(), vector<int>(s.size(), 0));
        for(int i=s.size()-1; i>=0; --i) {
            for(int j=i; j<s.size(); ++j) {
                if (i==j) {
                    m[i][j] = 1;
                    continue;
                }
                //j>=i+1;
                if (s[i] == s[j]) {
                    if (j>i+1) m[i][j] = m[i+1][j-1]+2;
                    else m[i][j] = 2;
                } else { 
                    m[i][j] = max(m[i+1][j], m[i][j-1]);
                    if (j>i+1) m[i][j] = max(m[i][j],  m[i+1][j-1]);
                }   
            }
        }
        return m[0][s.size()-1];
    }
};
