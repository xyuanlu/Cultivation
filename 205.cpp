/*
 * 205. Isomorphic Strings   [easy]
 * Given two strings s and t, determine if they are isomorphic.
 *
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 *
 * All occurrences of a character must be replaced with another character while preserving
 * the order of characters. No two characters may map to the same character but a character may map to itself.
 */
 
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m1, m2;
        for(int i=0; i<s.size(); ++i) {
            //if (s[i] == t[i])
             //   return false;
            if (m1.find(s[i]) != m1.end()) {
                if (m1[s[i]] != t[i])
                    return false;
            } else {
                m1[s[i]] = t[i];
            }
            if (m2.find(t[i]) != m2.end()) {
                if (m2[t[i]] != s[i])
                    return false;
            } else {
                m2[t[i]] = s[i];
            }
            
        }
        return true;
    }
};
