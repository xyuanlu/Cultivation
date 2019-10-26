/*
 * 451. Sort Characters By Frequency
 * Given a string, sort it in decreasing order based on the frequency of characters.
 */
 
class Solution {
public:
    class P{
    public:
        char c;
        int n;
        
        P(char cc, int nn): c(cc), n(nn) {};
        
        bool operator<(const P pp) const {
            return this->n > pp.n;
        }
        
    };
    
    string frequencySort(string s) {
        unordered_map<char, int> um;

        for(char &c:s) {
            um[c]++;
        }
        
        vector<P> m;
        for(auto &it:um) {
            //cout<<it.first<<" "<< it.second<<endl;
            m.push_back(P(it.first, it.second));
        }
        

        sort(m.begin(), m.end());
        
        string res;
        for(int i=0; i<m.size(); ++i) {
            char c = m[i].c;
            int count = m[i].n;
            //cout<<c<<" "<<count<<endl;
            while (count!=0) {
                res+=c;
                count--;
            }
        }
        return res;
    }
        
};
