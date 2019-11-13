/*
 * 616. Add Bold Tag in String
 */
 
class Solution {
public:
    class P{
    public:
        int a;
        int b;
        
        bool operator<(P pp) const {
            if (a == pp.a) {
                return b < pp.b;
            }
            return a < pp.a;
        }
    };
    string addBoldTag(string s, vector<string>& dict) {
        vector<P> m, mm;
        string res;
        
        for(int i=0; i<dict.size(); ++i) {
            auto found = s.find(dict[i], 0);
            while (found != string::npos) {
                //cout<<found<<endl;
                m.push_back({(int)found, (int)(found+dict[i].size())});
                found = s.find(dict[i], found+1);
            }
        }
        sort(m.begin(), m.end());
        
        //cout<<m.size()<<endl;
        
        // merge intervals in m;
        for(int i=0; i<m.size(); ++i) {
            int j = i+1;
            for(; j<m.size(); ++j) {
                if (m[j].a>m[i].b) {
                    break;
                }
                m[i].b = max(m[i].b, m[j].b);
            }
            mm.push_back(m[i]);
            i=j-1;
        }
        int idx = 0;
        // assemble res string
        for(int i=0; i<s.size(); ++i) {
            if (idx<mm.size() && i == mm[idx].a) {
                res += "<b>";
            }
            if (idx<mm.size() && i == mm[idx].b) {
                res += "</b>";
                ++idx;
            }
            res += s[i];
        }
        if(idx>=0 && idx == mm.size()-1 && mm[idx].b == s.size())
            res+="</b>";
        
        return res;
    }
};
