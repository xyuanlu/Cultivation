/*
 * 791. Custom Sort String
 * S and T are strings composed of lowercase letters. In S, no letter occurs more than once.
 *
 * S was sorted in some custom order previously. We want to permute the characters of T so that
 * they match the order that S was sorted. More specifically, if x occurs before y in S, then x
 * should occur before y in the returned string.
 */
 
 class Solution {
public:
    string customSortString(string S, string T) {
        // Count map for T. 
        vector<int> m(26, 0);
        for(char c:T) {
            m[c-'a']++;
        }
        string res;
        for(char c:S) {
            while(m[c-'a']>0) {
                res+=c;
                m[c-'a']--;
            }
        }
        for(int i=0; i<26; ++i) {
            while(m[i]>0) {
                char t = 'a'+i;
                res+=t;
                m[i]--;
            }
        }
        return res;
    }
};
