
    /*
     *  301 Remove Invalid Parentheses
     *  Backtracking + Pruning
     *  For each Parentheses,we can add or not add this to result. 
     *  We visit all possibilities and add valid result to res.
     */
    

// 4ms
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        // cound the number of left and right to be removed
        int l = 0, r = 0;
        for(char c:s) {
            if (c == '(') {
                ++l;
            }
            if (c == ')') {
                if(l>0) --l;
                else ++r;
            }
        }
        
        vector<string> res;
        string temp;
        //cout<<"##"<<l<<" "<<r<<endl;
        helper(res, s, temp, 0, l, r, 0/*current left*/, 0/*current right*/);
        return res;
    }
    
    void helper(vector<string>& res, const string& s, string temp, int idx,
                int trl /*to be removed left*/, int trr, int l/*cur left*/, int r) {
        
        //cout<<l<<" "<<r<<endl;
        if (r>l) return;
        if (idx == s.size()) {
            //cout<<temp<<" ";
            //cout<<trl<<" "<<trr<<endl;
            if (trl==0 && trr==0 && l==r)
                res.push_back(temp);
            return;
        }
        if (s[idx] !='(' && s[idx] !=')') {
            helper(res, s, temp+s[idx], idx+1, trl, trr, l, r);
        }
        if (s[idx] == '(') {
            // do not remove if prev is not removed
            helper(res, s, temp+s[idx], idx+1, trl, trr, l+1, r);
            if (trl>0 && (idx==0 || temp.back()!='(')) {
                helper(res, s, temp, idx+1, trl-1, trr, l, r);
            }
        }
        if (s[idx] == ')') {
            // do not remove if prev is not removed
            helper(res, s, temp+s[idx], idx+1, trl, trr, l, r+1);
            if (trr>0 && (idx==0 || temp.back()!=')')) {
                helper(res, s, temp, idx+1, trl, trr-1, l, r);
            }
        }
        
        
    }
};
    
/* 72 ms
class Solution {    
public:
    int min = INT_MAX;
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        set<string> visited;
        
        helper(s, res, visited, 0, "");
        return res;
    }
    
    void helper(const string& s, vector<string>& res, set<string>& visited, int cur, string temp) {
        int l=0, r=0;
        isValid(temp, l, r);
         // Pruning:
         // 1. If right >left (temp is not valid)
         // 2. If the total number of removed parentheses in temo is already larger than removed parentheses in the global optimal.
         
        if(visited.find(temp) != visited.end() || r>l || cur - temp.size() >min)
            return;
        if(cur == s.size()) {
            //cout<<temp<<endl;
            if (l!=r)
                return;
            if (res.size() != 0 && res[0].size()>temp.size())
                res.empty();
            if (res.size() == 0 || res[0].size()==temp.size()) {
                res.push_back(temp);
                min = s.size() - temp.size();
            }
            return;     
        }
        //cout<<temp<<endl;
        if(s[cur] != '(' && s[cur] != ')')
            return helper(s, res, visited, cur+1, temp+s[cur]);
        helper(s, res, visited, cur+1, temp+s[cur]);
        helper(s, res, visited, cur+1, temp);
        visited.insert(temp);                                        // <-------XXX We insert into visited here.
    }
    
    bool isValid(const string& s, int& l, int& r) {
        for(int i=0; i<s.size(); ++i) {
            if(s[i] == '(') ++l;
            if(s[i] == ')') ++r;
            if(r>l)
                return false;
        }
        return l == r;
    }
};
*/
