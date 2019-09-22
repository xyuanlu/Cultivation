/*
 * 22. Generate Parentheses
 * 
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 */
 
 class Solution {
public:
    // back trace
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string t;
        helper(n, 0 /*How many '(' used*/ , res, t);
        return res;
    }
    
    void helper(int n, int u, vector<string>& res, string& t) {
        if(u==n) {
            string r = t;
            for (int i=0; i<(2*u-t.size()); ++i) {
                r += ')';
            }
            res.push_back(r);
            return;
        }
        t+='(';
        helper(n, u+1, res, t);
        t.pop_back();
        // If we have ')' needed
        if (t.size()<2*u) {
            t+=')';
            helper(n, u, res, t);
            t.pop_back();
        }
    }
};
