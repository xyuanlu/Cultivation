/*
* 1316. Distinct Echo Substrings
*/

class Solution {
public:
    // worest case n*n
    
    int distinctEchoSubstrings(string text) {
        int res = 0;
        unordered_set<string> m;
        
        for(int l=1; l<=text.size()/2; ++l) {
            int i=0;
            int count = 0;
            while(i+l<text.size()) {
                int j = i+l;
                if (text[i] == text[j]) {
                    ++count;
                } else {
                    count = 0;
                }
                if (count >=l) {
                    //cout<<i<<" "<<l<<endl;
                    m.insert(text.substr(i-l+1, l));
                }
                ++i;
            }
        }
        
        return m.size();
    }
};
