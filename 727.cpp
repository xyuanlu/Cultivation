/*
 * 727. Minimum Window Subsequence
 * Given strings S and T, find the minimum (contiguous) substring W of
 * S, so that T is a subsequence of W.
 *
 * If there is no such window in S that covers all characters in T, return the empty
 * string "". If there are multiple such minimum-length windows, return the one with
 * the left-most starting index.
 */
 
class Solution {
public:
    string minWindow(string S, string T) {
        /*
         * Find the substr from S that contains all chars in T in the same order
         */
        
        // map of char <--> set of idx.
        /* Iterate through the first char's set of idx, the idx of
         * the enxt char is the upperbound of the idx in next char's set of idx.
         */
        unordered_map<char, set<int>> m;
        for(int i=0; i<S.size(); ++i) {
            m[S[i]].insert(i);
        }
        
        string res;
        int resIdx=-1, resLen = INT_MAX;
        for(int idx: m[T[0]]) {
            int prev = idx;
            int i=1;
            for (; i<T.size(); ++i) {
                auto it = m[T[i]].upper_bound(prev);
                if (it == m[T[i]].end()) {
                    break;
                }
                prev = *it;
            }
            if (i==T.size()) {
                int l = prev-idx+1;
                if (l<resLen) {
                    resLen = l;
                    resIdx = idx;
                }
            }
            
        }
        if (resIdx!=-1) {
            res = S.substr(resIdx, resLen);
        }
        return res;
    }
};
