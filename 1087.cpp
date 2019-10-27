/*
 * 1087. Brace Expansion
 *
 * A string S represents a list of words.
 * Each letter in the word has 1 or more options.  If there is one option, the letter is
 * represented as is.  If there is more than one option, then curly braces delimit the options. 
 * For example, "{a,b,c}" represents options ["a", "b", "c"].
 *
 * For example, "{a,b,c}d{e,f}" represents the list ["ade", "adf", "bde", "bdf", "cde", "cdf"].
 * 
 * Return all words that can be formed in this manner, in lexicographical order.  <<-------
 * 1 <= S.length <= 50
 * 2. There are no nested curly brackets.                                         <<--------
 * All characters inside a pair of consecutive opening and ending curly brackets are different.
 */
 
class Solution {
public:
    vector<string> expand(string S) {
        vector<string> res;
        string cur;
        
        helper(S, 0, cur, res);
        return res;
    }
    
    void helper(const string &S, int idx, string& cur, vector<string>& res) {
        if (idx == S.size()) {
            res.push_back(string(cur));
            return;
        }
        if (isalpha(S[idx])) {
            cur+=S[idx];
            helper(S, idx+1, cur, res);
            cur.pop_back();
            return;
        }
        // S[i] == '{';
        int s=idx;
        vector<char> next;
        for(; s<S.size(); ++s) {
            if (isalpha(S[s])) {
                next.push_back(S[s]);
            }
            if (S[s]=='}')
                break;
        }
        sort(next.begin(), next.end());     // aort here beats 100%
        for(int i=0; i<next.size(); ++i) {
            cur+=next[i];
            helper(S, s+1, cur, res);
            cur.pop_back();
            
        }
        //sort(res.begin(), res.end());    // sort here will beats 5% 
        return;
    }
};
