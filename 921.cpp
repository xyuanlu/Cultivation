/*
 * 921. Minimum Add to Make Parentheses Valid
 * 
 * Given a string S of '(' and ')' parentheses, we add the minimum number
 * of parentheses ( '(' or ')', and in any positions ) so that the resulting parentheses string is valid.
 */
 
 class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> m;
        int res=0;
        for(char c:S) {
            if(c=='(') {
                m.push(c);
            } else {
                if(m.empty()) {
                    res++;
                } else {
                    m.pop();
                }
            }
        }
        res +=m.size();
        return res;
    }
};
