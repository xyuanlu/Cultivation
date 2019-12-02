/*
* 132. Palindrome Partitioning II
*
* Given a string s, partition s such that every substring of the partition is a palindrome.
*
* Return the minimum cuts needed for a palindrome partitioning of s.
*/

class Solution {
public:
    int minCut(string s) {
        // [i, j] is palindrome
        vector<vector<int>> m(s.size(), vector<int>(s.size(), false));
        for(int i=s.size()-1; i>=0; --i) {
            for(int j=i; j<s.size(); ++j) {
                if (s[i] == s[j]) {
                    if (j<=i+2) {
                        m[i][j] = true;
                    } else {
                        m[i][j] = m[i+1][j-1];
                    }
                }
            }
        }
        
        // mm[i] is the min number of cut to reach i
        //mm[i] = min(mm[j] + 1) where mm[j+1][i] is true;
        vector<int> mm(s.size(), s.size());
        for(int i=0; i<s.size(); ++i) {
            for(int j=-1; j<i; ++j) {
                if (m[j+1][i]) {
                    int temp = j==-1? -1: mm[j];
                    mm[i] = min(mm[i], temp+1);
                }
            }
            //cout<<mm[i]<<endl;
        }
        return mm[s.size()-1];
    }
};
