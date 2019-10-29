/*
 * 772. Basic Calculator III
 *
 * "(2+6* 3+5- (3*14/7+2)*5)+3"  -->   -12
 */
 
 /*
* Lets write a classic parser
*
*       exp   -> term Rexp
*       Rexp  ->  + term Rexp
*               | - term Rexp
*               | epslon
*
*      term   -> factor Rterm
*      Rterm  ->  * factor Rterm
*               | / factor Rterm
*               | epslon
*
*      factor -> (exp)
*               | num
*               | epslon
*
* 
*   The result of parsing will get us a Reverse Polish notation (RPN).
*   Eval the PRN to get the final result
*/

class Solution {
public:
    int idx = 0;
    string S;
    
    class P{
    public:
        long long num;
        char op;
        
        P(long long nn, char c): num(nn), op(c) {};
    };
    
    vector<P> rpn;
    
    void exp() {
        term();
        rexp();
    }
    void rexp() {
        if (S[idx] == '+') {
            ++idx;
            term();
            rpn.push_back(P(0, '+'));      
            rexp(); 
        }
        else if (S[idx] == '-') {
            ++idx;
            term();
            rpn.push_back(P(0, '-')); 
            rexp(); 
        }
        else
            return;
    }
    
    // term -> factor rterm
    void term() {
        factor();
        rterm();
    }
    void rterm() {
        // rterm -> * factor rterm 
        if (S[idx] == '*') {
            ++idx;
            factor();
            rpn.push_back(P(0, '*'));        
            rterm(); 
        }
        // rterm -> / factor rterm 
        else if (S[idx] == '/') {
            ++idx;
            factor();
            rpn.push_back(P(0, '/'));        
            rterm(); 
        }
        else
            return;
        
    }
    
    void factor() {
        // factor -> (exp)
        if(S[idx]=='(') {
            ++idx;
            exp();
            assert(S[idx]==')');
            ++idx;
        }
        // factor -> num
        else if (S[idx]=='-' || isdigit(S[idx])){
            int sign = 1;
            if(S[idx]=='-') {
                sign = -1;
                idx++;
            }
            int l = 0;
            while((idx+l)<S.size() && isdigit(S[idx+l])) {
                ++l;
            }
            long long num = stoll(S.substr(idx, l));
            rpn.push_back(P(sign*num, 'n'));
            idx += l;
        }
        
    }
    
    int eval() {
        /*for(P &t:rpn) {
            if (t.op != 'n') {
                cout<<t.op<<" ";
            } else {
                cout<<t.num<<" ";
            }
        }*/
        int res = 0;
        stack<int> m;
        for(P& t:rpn) {
            if(t.op == 'n') {
                m.push(t.num);
            }
            else {
                int b = m.top();
                m.pop();
                int a = m.top();
                m.pop();
                int tt = cal(a, b, t.op);
                m.push(tt);
            }
        }
        return m.top();
        
        //return 0;
    }
    
    int cal(long long a, long long b, char op) {
        //cout<<a<<op<<b<<endl;
        if (op == '+') return a+b;
        if (op == '-') return a-b;
        if (op == '*') return a*b;
        if (op == '/') return a/b;
        return 0;
    }
    
    int calculate(string s) {
        for(auto c:s) {
            if (c==' ')
                continue;
            else
                S += c;
        }

        exp();
        int res = eval();
        return res;
    }
};
