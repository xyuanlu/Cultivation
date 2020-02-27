/*
 * 680. Valid Palindrome II
 * Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.
 */
 
class Solution {
public:
    bool validPalindrome(string s) {
        int i=0, j=s.size()-1;
        while (i<j) {
            if(s[i] != s[j]) {
                return (strictValidPalindrome(s, i, j-1) || strictValidPalindrome(s, i+1, j));
            }
            ++i;
            --j;
        }
        return true;
    }
    
    bool strictValidPalindrome(string& s, int i, int j) {
        int m=i, n=j;
        while (m<n) {
            //cout<<m<<n<<endl;
            if(s[m] != s[n])
                return false;
            ++m;
            --n;
        }
        return true;
    }
};
