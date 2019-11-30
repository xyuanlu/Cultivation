/*
 *  214. Shortest Palindrome
 * Given a string s, you are allowed to convert it to a palindrome by adding characters in
 * front of it. Find and return the shortest palindrome you can find by performing this transformation.
 */
 
class Solution {
public:
    string shortestPalindrome(string s) {
        // [0, i) always contain the longest parlindrome
        int i=0;
        for(int j=s.size()-1; j>=0; --j) {
            if (s[i] == s[j]) {
                ++i;
            }
        }
        if (i==s.size())
            return s;
        
        string str = s.substr(i);
        reverse(str.begin(), str.end());
        return str + shortestPalindrome(s.substr(0, i)) + s.substr(i);
        
        
        /* TLE
        if (s.size()==0)
            return s;
        
        // find the longest palindrome starting idx 0
        // m[i][j] == true means [i,j] is palindrome
        vector<vector<bool>> m(s.size(), vector<bool>(s.size(), 0));
        for (int i=m.size()-1; i>=0; --i) {
            for (int j=i; j<m.size(); ++j) {
                if (s[i] == s[j]) {
                    if (j<=i+2) {
                        m[i][j] = true;
                    } else {
                        m[i][j] = m[i+1][j-1];
                    }
                }
            }
        }
        int len=0, j=1;
        while (j<s.size()) {
            if (m[0][j]) {
                len = j;
            } 
            ++j;
        }
        //cout<<len<<endl;
        if (len == s.size()-1)
            return s;
        string str = s.substr(len+1, s.size()-len-1);
        reverse(str.begin(), str.end());
        string res = str + s;
        return res;*/
    }
};
