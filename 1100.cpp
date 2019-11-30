/*
 * 1100. Find K-Length Substrings With No Repeated Characters
 * Given a string S, return the number of substrings of length K with no repeated characters.
 */
 
class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        if (K > S.size())
            return 0;
        int n = 0, i=0, j=0, res = 0;
        unordered_map<char, int> m;
        while(j<K) {
            m[S[j]] ++;
            if (m[S[j]] >1) n++;
            ++j;
        }

        while(j<S.size()) {
            if (n==0) {
                //cout<<i<<" "<<S.substr(i, K)<<endl;
                res++;
            }
            if (m[S[i]]>1) {
                n--;
            }
            m[S[i]]--;
            ++i;
            m[S[j]] ++;
            if (m[S[j]] >1) n++;
            ++j;
        }
        if (n==0)
            res++;
        return res;
    }
};
