/*
 * 71. Simplify Path
 */
 
 class Solution {
public:
    string simplifyPath(string path) {
        if(path == "..")
            return "/../";
        vector<string> ss;
        string res;
        split(path, ss);
        deque<string> m;
        for(auto s:ss) {
            if(s.size()==0)
                continue;
            if (s == ".") {
                continue;
            }
            if (s == ".." ) {
                if(!m.empty())
                    m.pop_back();
                continue;
            }
            m.push_back(s);
        }
        while(!m.empty()) {
            res += "/" + m.front();
            m.pop_front();
        }
        return res.size()==0? "/":res;
    }
    
    void split(const string& s, vector<string>& ss) {
        int prev = 0;
        while(s[prev] == '/') ++prev;
        for(int i=prev; i<=s.size(); ++i) {
            if(i == s.size() || s[i] == '/') {
                ss.push_back(s.substr(prev, i-prev));
                prev = i+1;
            }
        }
        /*for(auto i:ss) {
            cout<<i<<" ";
        }*/
    }
};
