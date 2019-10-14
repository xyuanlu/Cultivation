/*
* 150. Evaluate Reverse Polish Notation 
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> m;
        set<string> opr = {"+","-", "*", "/"};
        
        for (string &s: tokens) {
            if (opr.find(s) != opr.end()) {
                int b = m.top();   //<<<<<---- top of stack is the second one
                m.pop();
                int a = m.top();
                m.pop();
                int c = 0;
                
                if (s=="+") {
                    c = a+b;
                
                }
                if (s=="-") {
                    c = a-b;
                
                }
                if (s=="*") {
                    c = a*b;
                
                }
                if (s=="/") {
                    c = a/b;
                
                }
                //cout<<c<<endl;
                m.push(c);
            } else {
                m.push(stoi(s));
            }
        }
        
        return m.top();
    }
};
