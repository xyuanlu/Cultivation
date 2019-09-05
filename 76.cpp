/*
 * Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
 * 
 * Example:
 *
 *  Input: S = "ADOBECODEBANC", T = "ABC"
 *  Output: "BANC"
 *
 * Note:
 *  If there is no such window in S that covers all characters in T, return the empty string "".
 *  If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
 *
 */
 
class Solution {
public:
    string minWindow(string s, string t) {
        /*
         * Classic problem for 2 pointer.
         * We have a vector<int> 256 tracking the needed numebr for each letter. 
         * If a letter is not in string 't', then the needed number if 0.
         *
         * Whenever right pointer meets a letter and completes pattern (count==0)
         * we count length and move left pointer towards right pointer. 
         * Break the while loop if after left pointer's move, memo[s[l]]>0 (we have debt)
         * 
         * Every move for right pointer
         *      first count-- if the we have > 0 needed.  
         *      then unconditioanlly, memo[s[r]]-- (minus value means we have x to spare)
         *      
         * Every move for right pointer
         *      first  unconditioanlly, memo[s[l]] ++
         *      then count-- if the we have > 0 needed.
         */
        
        vector<int> m(256, 0);
        int l=0, r=0, begin = -1, count = t.size(), minLen = s.size()+1;
        
        for(char c:t) {
            m[c] ++;
        }
        
        while(r<s.size()) {
            if (m[s[r]]>0) {
                count--;
            }
            m[s[r]]--;
            while(count ==0 && l<=r) {
                if (r-l+1 < minLen) {
                    minLen = r-l+1;
                    begin = l;
                }
                m[s[l]]++;
                if (m[s[l]]>0) {   
                    // m[s[l]] is in T and we do not have a spare in the l->r sequence. 
                    // This will be the minLen for this run
                    count++;
                    l++;
                    break;
                }
                l++;
            }
            r++;
        }
        return begin==-1? "" : s.substr(begin, minLen);
    }
};


