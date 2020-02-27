/*
 * 438. Find All Anagrams in a String
 */
 
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> m(26, 0);
        vector<int> res;
        if(s.size() < p.size())
            return res;
        for(char c:p) {
            m[c-'a']++;
        }
        
        int l=0, r=l, found = 0;
        vector<int> t = m;
        /*
         * vector<int> temp records the number of needed chars.
         * found ++ if temp[c]>0; 
         */
        while(l<=s.size()-p.size()) {
            //cout<<l<<endl;
            if( t[s[r]-'a']>0) {  // We have at least 1 needed char s[t[l]]
                t[s[r]-'a'] --;
                found ++;
                if(found ==p.size()) {
                    res.push_back(l);
                    while(r<s.size() && s[r+1] == s[l++]) {
                        res.push_back(l);
                        ++r;
                    }
                    //l = l+1;
                    t = m;
                    r = l;
                    found = 0;
                } else {
                    r++;
                }
            } else if (m[s[r]-'a'] == 0) { // we do not need this char at all
                l = r+1;
                t = m;
                r = l;
                found = 0;
            } else {            // s[t[r]] is in p, but we already have enough
                l = l+1;
                t = m;
                r = l;
                found = 0;
            }
        }
        
        return res;
    }    
};
