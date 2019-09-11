/*
 *  940. Distinct Subsequences II
 *
 */
 
 class Solution {
public:
    int distinctSubseqII(string S) {
        unsigned long long M = 1e9 + 7;
        vector<int> memo(S.size(), 1);
        for(int i=1; i<S.size(); ++i) {
            int j=i-1;
            for(; j>=0; --j) {
                if (S[j] == S[i]) {
                    break;
                }
            }
            if (j>0) {
                //cout<<j<<"found"<<endl;
                memo[i] = (2*memo[i-1])%M - memo[j-1];
            } else if (j==0) {
                memo[i] = (2*memo[i-1])%M;
            } else {
                memo[i] = (2*memo[i-1])%M+1;
            } 
            memo[i] = (memo[i] + M) % M;
            //cout <<memo[i] <<endl;
        }
        return memo[S.size()-1];
    }
};
