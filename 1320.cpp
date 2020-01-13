/*
 * 1320. Minimum Distance to Type a Word Using Two Fingers
 */
 
class Solution {
public:
    // m[i][j] : types previous i-1 chars, 
    /* 
     * last word :
     * ..... j ..P C
     *       R   L
     * 
     * Use same finger
     * .... j ..P C
     *      R     L       m[i+1][j] = m[i][j] + dis(P->c)
     *
     * Use the other finger
     * .... j ..P C
     *          L R       m[i+1][p] = m[i][j] + dis(j->C)
     */
    
    
    int minimumDistance(string word) {
        vector<vector<int>> m(word.size(), vector<int>(26, INT_MAX));
        for(int j=0; j<26; ++j) {
            m[0][j] = 0;
        }
        
        for(int i=0; i<word.size()-1; ++i) {
            int p = word[i] - 'A';
            int c = word[i+1] - 'A';
            for(int j=0; j<26; ++j) {
                m[i+1][j] = min(m[i+1][j], m[i][j] + dis(p, c));
                m[i+1][p] = min(m[i+1][p], m[i][j] + dis(j, c));
            }
        }
        
        int res = INT_MAX;
        for(int j=0; j<26; ++j) {
            res = min(res, m[word.size()-1][j]);
        }
        
        return res;
    }
    
    
    /* ----------------------------- recursive -----------------------------*/
    int minimumDistance1(string word) {
        // m[k][l][r] -> min cosr for substr k->end, left hand at char l, right hand at char r.
        vector<vector<vector<int>>> m(word.size(), vector<vector<int>>(27, vector<int>(27, -1)));
        
        return helper(0, 26, 26, m, word);
    }
    
    int helper(int k, int l, int r, vector<vector<vector<int>>>& m, string& word) {
        if (k==word.size()) return 0;
        if (m[k][l][r]!=-1)
            return m[k][l][r];
        int c = word[k] - 'A';
        int res = min(helper(k+1, c, r, m, word) + dis1(l, c), helper(k+1, l, c, m, word) + dis1(r, c));
        m[k][l][r] = res;
        return res;
    }
    
    int dis1(int c1, int c2) {
        if (c1==26) return 0;
        return abs(c1/6 - c2/6) + abs(c1%6 - c2%6);
    }
    
    
    /*----------------------------- iteration - bottom up -----------------------------*/ 
    int minimumDistance2(string word) {
        // m[k][l][r] -> finished typping previous k-1 chars, left hand at char l, right hand at char r.
        vector<vector<vector<int>>> m(word.size(), vector<vector<int>>(26, vector<int>(26, INT_MAX)));
        
        for(int i=0; i<26; ++i) {
            for(int j=0; j<26; ++j) {
                m[0][i][j] = 0;
            }
        }
        
        for (int k=1; k<word.size(); ++k) {
            int c = word[k-1] - 'A';
            for(int l=0; l<26; ++l) {
                for(int r=0; r<26; ++r) {
                    if ((l != word[k]-'A') && (r != word[k]-'A')) continue;
                    m[k][l][r] = min((m[k-1][l][c] + dis(c, r)),   // Origional at c, type and then move from c to r.
                                     (m[k-1][c][r] + dis(c, l)));
                }
            }
        }
         
        int res = 10000;
        for(int i=0; i<26; ++i) {
            res = min(res, min(m[word.size()-1][word.back()-'A'][i], m[word.size()-1][i][word.back()-'A']));
        }
            
        return res;
        
    }
    
    int dis(int c1, int c2) {
        return abs(c1/6 - c2/6) + abs(c1%6 - c2%6);
    }
};
