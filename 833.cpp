/*
 * 833. Find And Replace in String
 */
 
class Solution {
public:
    class P{
    public:
        int idx;
        int j;
        
        bool operator<(P p) const {
            return idx < p.idx;
        }
    };
    
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        string res;
        vector<P> m;
        
        
        for(int i=0; i<indexes.size(); ++i) {
            m.push_back({indexes[i], i});
        }
        
        sort(m.begin(), m.end());
        /*for(int i=0; i<m.size(); ++i) {
            cout<<m[i].idx<<" "<<m[i].j<<endl;
        }*/
        
        
        int id = 0;
        int i=0;
        for(;i<S.size(); ++i) {
            if (id>=indexes.size())
                break;
            int idx = m[id].j;
            //cout<<id<<" "<<idx<<endl;
            if (indexes[idx] != i) {
                res += S[i];
                continue;
            }
            int l = sources[idx].size();
            if (S.substr(indexes[idx], l) != sources[idx]) {
                res += S[i];
                id++;
                continue;
            }
            res += targets[idx];
            id++;
            i+=l-1;
        }
        while(i<S.size()) {
            res+=S[i];
            ++i;
        }
        
        return res;
    }
};
