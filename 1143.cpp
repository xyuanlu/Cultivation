/*
 * 1143. Longest Common Subsequence
 * Given two strings text1 and text2, return the length of their longest common subsequence.
 *
 * A subsequence of a string is a new string generated from the original string with some
 * characters(can be none) deleted without changing the relative order of the remaining characters.
 * (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is
 * a subsequence that is common to both strings.
 *
 * there is no common subsequence, return 0.
 */
 
 class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int m=s1.size(), n=s2.size();
        vector<vector<int>> memo(m, vector<int>(n, 0));
        for (int i=0; i<n; ++i) {
            if(s1[0] == s2[i] || (i>0 && memo[0][i-1] ==1))
                memo[0][i] = 1;
        }
        for (int j=0; j<m; ++j) {
            if(s2[0] == s1[j] || (j>0 && memo[j-1][0] == 1))
                memo[j][0] = 1;
        }
        
        for (int i=1; i<m; ++i) {
            for (int j=1; j<n; ++j) {
                if (s1[i] == s2[j]) {
                    memo[i][j] = 1+memo[i-1][j-1];
                } else {
                    memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
                }
            }
        }
        return memo[m-1][n-1];
    }
};
