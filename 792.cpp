/*
 * 792. Number of Matching Subsequences
 * Given string S and a dictionary of words words, find the number of words[i] that is a subsequence of S.
 *
 * Example :
 *  S = "abcde"
 *  words = ["a", "bb", "acd", "ace"]
 *  Output: 3
 *  Explanation: There are three words in words that are a subsequence of S: "a", "acd", "ace".
 */
 
 class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int res = words.size();
        vector<set<int>> memo(26, set<int>());
        for(int i=0; i<S.size(); ++i) {
            memo[S[i]-'a'].insert(i);
        }
        for(int i=0; i<words.size(); ++i) {
            int prevIdx = -1;
            for(int j=0; j<words[i].size(); ++j) {
                auto t = memo[words[i][j]-'a'].upper_bound(prevIdx);
                if(t == memo[words[i][j]-'a'].end()){
                    res--;
                    break;
                }
                prevIdx = *t;
            }
        }
        return res;
    }
};
