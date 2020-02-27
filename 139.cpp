/*
 * 139. Word Break
 */
 
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(string& ss: wordDict) {
            dict.insert(ss);
        }
        
        //m[i] -> is we can break till endidx is i;
        vector<int> m(s.size()+1, false);
        m[0] = true;
        
        for(int i=0; i<=s.size(); ++i) {
            if (m[i] == false)
                continue;
            for(int l=1; i+l<=s.size(); ++l) {
                if(m[i+l]==true)
                    continue;
                if (dict.find(s.substr(i, l)) != dict.end()) {
                    m[i+l] = true;
                }
            }
        }
        
        return m[s.size()];
    }
};
