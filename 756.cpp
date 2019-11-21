/*
 * 756. Pyramid Transition Matrix
 */

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        int N = bottom.size();
        string cur;
        
        unordered_map<string, vector<char>> m;
        for (string &s:allowed) {
            m[s.substr(0,2)].push_back(s[2]);
        }
        
        return helper(bottom, cur, m, N-1);
    }
    
    bool helper(string& prev, string& cur,
                unordered_map<string, vector<char>>& m, int N) {
        if (N==0) {
            return true;
        }
        if (cur.size() == N) {
            string next;
            //cout<<cur<<endl;
            return helper(cur, next, m, N-1);
        }
        int i = cur.size();
        string ss;
        ss += prev[i];
        ss += prev[i+1];
        //cout<<ss<<endl;
        if (m.find(ss) == m.end())
            return false;
        
        for(char c:m[ss]) {
            cur+=c;
            if (helper(prev, cur, m, N))
                return true;
            cur.pop_back();
        }
        return false;
        
    }
};
