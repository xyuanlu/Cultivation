class Solution {
    /*
     *  Backtracking + Pruning
     *  For each Parentheses,we can add or not add this to result. 
     *  We visit all possibilities and add valid result to res.
     */
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
        /*
         * Pruning:
         * 1. If right >left (temp is not valid)
         * 2. If the total number of removed parentheses in temo is already larger than removed parentheses in the global optimal.
         */
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
