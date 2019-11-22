/*
 * 291. Word Pattern II
 */
 
class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char, string> m;
        unordered_set<string> used;
        return helper(pattern, str, 0, 0, m, used);
    }
    
    bool helper(string &pattern, string &str, int pidx, int sidx,
                unordered_map<char, string>& m, unordered_set<string>& used){
        //cout << pattern.size() << " " << pidx << " " << str.size() << " " << sidx <<endl;
        if (pidx == pattern.size() || sidx == str.size()) {
            return pidx == pattern.size() && sidx == str.size();
        }
        //cout << pattern.size() << " " << pidx << " " << str.size() << " " << sidx <<endl;
        if (m.find(pattern[pidx]) != m.end()) {
            int l = m[pattern[pidx]].size();
            string temp = str.substr(sidx, l);
            if (temp ==  m[pattern[pidx]]) {
                return helper(pattern, str, pidx+1, sidx+l, m, used);
            } else {
                return false;
            }
        }
        
        for(int l=1; sidx+l <= str.size(); ++l) {
            if (str.size()-(sidx+l) < pattern.size()-pidx-1)
                return false;
            string temp = str.substr(sidx, l);
            if (used.find(temp) != used.end())
                continue;
            m[pattern[pidx]] = temp;
            used.insert(temp);
            //cout<<pattern[pidx]<<" "<<temp<<endl;
            if (helper(pattern, str, pidx+1, sidx+l, m, used))
                return true;
            m.erase(pattern[pidx]);
            used.erase(temp);
        }
        return false;
    }
};
