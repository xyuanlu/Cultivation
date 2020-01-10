/*
 * 1249. Minimum Remove to Make Valid Parentheses
 */
 
 class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> m;
        for(int i=0; i<s.size(); ++i) {
            if (s[i] =='(') {
                m.push(i);
            } else if (s[i] == ')'){
                if (m.empty()) {
                    s[i] = '*';
                } else {
                    m.pop();
                }
            }
        }
        
        while(!m.empty()) {
            s[m.top()] = '*';
            m.pop();
        }
        
        string res;
        for(int i=0; i<s.size(); ++i) {
            if (s[i] != '*') {
                res += s[i];
            }
        }
        
        return res;
    }
    
    /*
    string minRemoveToMakeValid(string s) {
        unordered_set<int> m;
        
        // remember to be removed ')'
        int count=0;
        for(int i=0; i<s.size(); ++i) {
            if (s[i] == '(') ++count;
            if (s[i] == ')') {
                if(count>0) --count;
                else m.insert(i);                
            }
        }
        
        
        // remember tobe removed '('
        count=0;
        for(int i=s.size()-1; i>=0; --i) {
            if (s[i] == ')' && m.find(i)==m.end()) ++count;
            if (s[i] == '(') {
                if(count>0) --count;
                else m.insert(i);                
            }
        }
        
        string res;
        for(int i=0; i<s.size(); ++i) {
            if (m.find(i) == m.end()) {
                res += s[i];
            }
        }
        return res;
    }*/
};
