/* 
 * 44. Wildcard Matching
 * 
 * Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.
 *  '?' Matches any single character.
 *  '*' Matches any sequence of characters (including the empty sequence).
 *  The matching should cover the entire input string (not partial).
 *
 */

class Solution {
public:
    /*
     * Text book like two string matching DP problem.
     * Similar to 115	Distinct Subsequences and 1143. Longest Common Subsequence.
     */

    bool isMatch(string s, string p) {
        int M=s.size(), N = p.size();
        vector<vector<bool>> m(M+1, vector<bool>(N+1, false));
        m[0][0] = true;
        int x=0;
        while(p[x] == '*' && x<p.size()) {
            m[0][x+1] = true;
            ++x;
        }
        
        for (int i=0; i<M; ++i) {
            for (int j=0; j<N; ++j) {
                if (p[j] == '?' || p[j] == s[i]) {
                    m[i+1][j+1] = m[i][j];
                    continue;
                }
                if (p[j] == '*') {
                    m[i+1][j+1] = m[i][j+1] || m[i+1][j];
                }
            }
        }
        /*for (int i=0; i<=M; ++i) {
            for (int j=0; j<=N; ++j) {
                cout<<m[i][j]<<" ";
            }
            cout<<endl;
        }*/
        
        return m[M][N];
    }
};
