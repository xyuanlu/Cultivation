/*
* 763. Partition Labels
* A string S of lowercase letters is given. We want to partition this
* string into as many parts as possible so that each letter appears in at
* most one part, and return a list of integers representing the size of these parts.
*/

class Solution {
public:
    class P{
    public:
        int s;
        int e;
        
        bool operator<(const P& p) const {
            return s < p.s;
        }
    };
    
    vector<int> partitionLabels(string S) {
        
        // the first and last occurance of a char is an interval
        // merge all overlap intervals
        unordered_map<char, P> m;
        
        for(int i=0; i<S.size(); ++i) {
            if (m.find(S[i]) != m.end()) {
                m[S[i]].e = i;
            }
            else {
                m[S[i]] = P{i, i};
            }
        }
        
        vector<P> mm;
        for (auto &it:m) {
            mm.push_back(it.second);
        }
        sort(mm.begin(), mm.end());
        
        vector<int> res;
        int start = mm[0].s, end = mm[0].e;
        for(int i=1; i<mm.size(); ++i) {
            if (mm[i].s > end) {
                res.push_back(end-start+1);
                start = mm[i].s;
                end = mm[i].e;
                continue;
            }
            end = max(end, mm[i].e);
        }
        res.push_back(end-start+1);
        return res;
    }
};

