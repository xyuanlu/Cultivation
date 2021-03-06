/*
 *567. Permutation in String
 * Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1.
 * In other words, one of the first string's permutations is the substring of the second string.
 */
 
 /*
  * This is a easy version of Substring with Concatenation of All Words
  *
  * 1. Compute a RefMap (vector<int>(26)) for all chars in S1. The map wont be changed after being computed.
  * 2. Starting from each idx in s2 (start), 'idx' ++ and compute and update a new RefMap m and 'count;
  *    1). If memo[s2[i-'a']] already reached its needed number but count<0 start from 'start+1'
  *    2). If memo[s2[i-'a']] haven't reached its needed number, memo[s2[i-'a']]++ and update count
  *        After count is updated, see if we can return true. 
  */
 
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> c(26, 0);  // Ref count map
        for(char it:s1) {
            c[it-'a']++;
        }
        //for(auto it:c) {cout<<it;} cout<<endl;
        int start = 0, count = 0;
        vector<int> m(26, 0);
        for(int i=0; i<s2.size();) {
            //cout<<s2[i]<<" "<<start<<" "<<count<<endl;
            // not in s2
            if (c[s2[i]-'a'] ==0) {
                m = vector<int>(26, 0);
                ++i;
                start = i;
                count = 0;
                continue;
            }
            if(m[s2[i]-'a'] == c[s2[i]-'a']) {
                count = 0;
                start ++;
                i=start;
                m=vector<int>(26, 0);
                continue;
            }
            if(m[s2[i]-'a'] <= c[s2[i]-'a']) {
                count ++;
                m[s2[i]-'a']++;
                i++;
            }
            if(count == s1.size()) {
                return true;
            }
        }
        return false;
    }
};
