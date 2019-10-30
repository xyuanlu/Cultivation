/*
 * 736. Parse Lisp Expression
 */
 
 /*
 *      exp ->  (exp)
 *          | let eval exp
 *          | add exp exp      return parse(exp)+parse(exp)
 *          | mult exp exp      return parse(exp)*parse(exp)
 *          | num                return num
 *          | ident              return value of x
 *
 *      eval -> ident exp eval
 *          | epslon
 */

class Solution {
public:
    int idx = 0;
    string S;
    stack<unordered_map<string, int>> m;
    
    int exp() {
        //cout<<idx<<" "<<S[idx]<<endl;
        // exp -> (exp)
        if (S[idx] == '(') {
            ++idx;
            int t = exp();
            //cout<<"end "<<idx<<endl;
            assert(S[idx]==')');
            ++idx;
            return t;
        }
        // exp -> add exp exp
        if (idx<S.size()-2 && S.substr(idx, 3)=="add") {
            idx+=4;
            int a = exp();
            ++idx;
            int b = exp();
            return a+b;
        }
        // exp -> mult exp exp
        if (idx<S.size()-3 && S.substr(idx, 4)=="mult") {
            //cout<<"multi"<<endl;
            idx+=5;
            int a = exp();
            ++idx;
            int b = exp();
            cout<<a<<" * "<<b<<endl;
            return a*b;
        }
        // exp -> let eval exp
        if (idx<S.size()-2 && S.substr(idx, 3)=="let") {
            if (!m.empty()) {
                unordered_map<string, int> t = m.top();
                m.push(t);
            }
            else {
                m.push(unordered_map<string, int>());
            }
            idx+=4;
            eval();
            int c = exp();
            //assert(S[idx] = ')');
            //idx++;
            m.pop();
            //cout<<"eval return: "<<c<<endl;
            return c;
        }
        // exp -> num 
        if (S[idx] == '-' || isdigit(S[idx])) {
            int l = 0;
            while(S[idx+l] == '-' || isdigit(S[idx+l])) {
                ++l;
            }
            int n = stoi(S.substr(idx, l));
            cout<<n<<endl;
            idx+=l;
            return n;
        }
        // exp -> ident
        else {
            assert(isalpha(S[idx]));
            int l =0;
            while(idx+l<S.size() && S[idx+l]!=' ' && S[idx+l]!=')') {
                ++l;
            }
            string var = S.substr(idx, l);
            int n = m.top()[var];
            cout<<"ident: "<<idx<<" "<<var<<": "<<n<<endl;
            idx+=l;
            return n;
        }
        
    }
    
    void eval() {
        if (!isalpha(S[idx])) {
            //cout<<"exp "<<idx<<endl;
            return;
        }
        string var;
        int l = 0;
        while(idx+l<S.size() && S[idx+l]!=' ') {
            if (S[idx+l] == ')')
                return;
            ++l;
        }
        var = S.substr(idx, l);
        idx += l+1;
        int b = exp();
        m.top()[var] = b;
        idx++;
        cout<<var<<": "<<b<<endl;
        eval();
    }
    
    int evaluate(string expression) {
        S = expression;
        return exp();
    }
};
