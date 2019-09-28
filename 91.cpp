/*
 * 91. Decode Ways
 * 
 * 12 -> AB or L
 */
 
class Solution {
public:
    int numDecodings(string s) {
        // Ways to decode a string ends at idx
        vector<int> m(s.size()+1, 0);
        m[0] = 1;
        for(int i=1; i<=s.size(); ++i) {
            if(s[i-1]!='0') {
                m[i]+=m[i-1];
            }
            if(i>=2) {
                int temp = (s[i-2]-'0')*10 +(s[i-1]-'0');
                if(s[i-2]!='0' && temp <=26 && temp >0) {
                    m[i] +=m[i-2];
                }
            }
            //cout<<m[i]<<endl;
        }
        return m[s.size()];
        
    }
    
};
