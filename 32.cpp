/*
 * 32. Longest Valid Parentheses
 * 
 * Given a string containing just the characters '(' and ')', find the
 * length of the longest valid (well-formed) parentheses substring.
 */
 
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> m;
        int res = 0;
        m.push(-1);
        // stack maintains all unmatched index, either ( or )
        for(int i=0; i<s.size(); ++i) {
            int t = m.top();
            if (t!=-1 && s[i] == ')' && s[t] == '(') {
                m.pop();
                //cout<<i<<" "<<m.top()<<endl;
                res = max(res, i-m.top());
            } else {
                m.push(i);
            }
        }
        return res;
    }
};
