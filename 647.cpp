/*
 * 647. Palindromic Substrings
 * 
 * Given a string, your task is to count how many palindromic substrings in this string.
 * The substrings with different start indexes or end indexes are counted as different
 * substrings even they consist of same characters.
 */
 
class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        vector<vector<bool>> m(s.size(), vector<bool>(s.size(), 0));
        /*
         * For DP function like this, i from end to begin.
         */
        for(int i=s.size()-1; i>=0; --i) {
            for(int j=i; j<s.size(); ++j) {
                if(j<i) {
                    continue;
                }
                if(j==i) {
                    m[i][j] = true;
                    res++;
                    continue;
                }
                if(s[i] == s[j]) {
                    //cout<<i<<" "<<j<<" "<<m[i+1][j-1]<<endl;
                    if(j==i+1 || m[i+1][j-1]){
                        //cout<<i<<" "<<j<<endl;
                        m[i][j] = true;
                        res++;
                    }
                }
            }
        }
        return res;
    }
};
