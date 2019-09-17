/*
 * 10. Regular Expression Matching
 * 
 * Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
 *  '.' Matches any single character.
 *  '*' Matches zero or more of the preceding element.
 *  The matching should cover the entire input string (not partial).
 *
 * s and p is always valid
 */
 
 class Solution {
public:
    bool isMatch(string s, string p) {
        int M = s.size(), N = p.size();
        vector<vector<bool>> m(M+1, vector<bool>(N+1, false));
        
        m[0][0] = true;
        for(int j=1; j<N; ++j) {
            if(p[j]=='*')
                m[0][j+1] = m[0][j-1];
        }
        
        for(int i=0; i<M; ++i) {
            for(int j=0; j<N; ++j) {
                if (s[i] == p[j] || p[j] =='.') {
                    m[i+1][j+1] = m[i][j];
                    continue;
                }
                /* m[i][j] iff.
                 *  1) "b" "ba*"      m[i][j-2] == true
                 *  2) "baa" "ba*"    p[j-1] == s[i] && m[i-1][j] == true
                 */
                if (p[j] == '*') {
                    if ( m[i+1][j-1] ||
                        ((p[j-1] == s[i] || p[j-1] == '.') && m[i][j+1])){
                        m[i+1][j+1] = true;
                    }
                }
            }
        }
        
        /*for(int i=0; i<=M; ++i) {
            for(int j=0; j<=N; ++j) {
                cout<<m[i][j]<<" ";
            }
            cout<<endl;
        }*/
        
        return m[M][N];
    }
};
