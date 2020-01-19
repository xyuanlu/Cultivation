/*
 * 730. Count Different Palindromic Subsequences
*/
class Solution {
public:
    int countPalindromicSubsequences(string S) {
        int M = S.size();
        vector<vector<int>> m(M, vector<int>(M, -1));
        
        return helper(S, 0, M-1, m);
    }
    
    int helper(string& s, int i, int j, vector<vector<int>>& m) {
        long long MOD = 1e9+7;
        //cout<<i<<" "<<j<<"-> ";
        if (i>j)
            return 0;
        if (m[i][j]!=-1) {
            return m[i][j];
        }
        if (j==i) {
            m[i][j] = 1;
            return 1;
        }
        long long temp;
        // j>= i+1
        if (s[i] != s[j]) {
            // s[i][j] = s[i+1][j] + s[i][j+1] - s[i+1][j-1]
            temp = helper(s, i+1, j, m) + helper(s, i, j-1, m)
                      - helper(s, i+1, j-1, m);
        } else {  // s[i] == s[j]
            int l = i+1, r = j-1;
            while(l<=r && (s[l]!=s[i] || s[r]!=s[j])) {
                if (s[l] != s[i]) ++l;
                if (s[r] != s[j]) --r;
            }
            // axyza
            if (l>r) {
                temp = 2*helper(s, i+1, j-1, m) % MOD + 2;
            } else if (l==r) {  // axaya
                temp = 2*helper(s, i+1, j-1, m) + 1;
            } else {    // axxayyaxxa
                temp = 2*helper(s, i+1, j-1, m) - helper(s, l+1, r-1, m);
            }
        }
        //cout<<m[i][j]<<endl;
        m[i][j] = (temp + MOD)%MOD;
        return m[i][j];
    }
};
