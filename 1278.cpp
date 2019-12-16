/*
 * 1278. Palindrome Partitioning III
 * You are given a string s containing lowercase letters and an integer k. You need to :
 * 
 * First, change some characters of s to other lowercase English letters.
 * Then divide s into k non-empty disjoint substrings such that each substring is palindrome.
 * Return the minimal number of characters that you need to change to divide the string.
 */
 
 class Solution {
public:
    int palindromePartition(string s, int k) {
        /* m[i][j] is the min change of char for sub(i, j) [i, j]
         * to be palindrom
         */
        
        int M = s.size();
        vector<vector<int>> m(M, vector<int>(M, 1000));
        
        for(int i=s.size()-1; i>=0; --i) {
            for(int j=i; j<s.size(); ++j) {
                if (i==j) {
                    m[i][j] = 0;
                    continue;
                } 
                if (s[i] == s[j]) {
                    if (j==i+1)
                        m[i][j] = 0;
                    else 
                        m[i][j] = m[i+1][j-1];
                        
                }
                else  {
                    if (j==i+1)
                        m[i][j] = 1;
                    else 
                        m[i][j] = m[i+1][j-1]+1;
                    
                }
            }
        }
        
        /*for(int i=0; i<M; ++i) {
            for (int j=0; j<M; ++j) {
                cout<<m[i][j]<<" ";
            }
            cout<<endl;
        }*/
        
        cout<<"kk"<<endl;
        /* mm[i][h] min number of change to partidion
         * substr(0, i) from (0, i]  into k parlindroms
         * mm[i][h] = min(mm[j][h-1] + m[j][i-1])
         */
        /*vector<vector<int>> mm(M+1, vector<int>(k+1, 1000));
        for(int i=1; i<=M; ++i) {
            for(int h=i; h<=k; ++h) {
                for (int j=1; j<i; ++j) {
                    mm[i][h] = min(mm[i][h], mm[j][h-1] + m[j][i-1]);
                }
            }
            
        }
        
        return mm[M][k];*/
        
        vector<vector<int>> mm(M+1, vector<int>(k+1, -1));
        helper(M, k, mm, m);
        return mm[M][k];
    }
    
    int helper(int i, int h, vector<vector<int>>& mm, vector<vector<int>>& m) {
        if (mm[i][h] != -1)
            return mm[i][h];
        if (h>i)
            return 1000;
        if (h==1) {
            mm [i][h] = m[0][i-1];
            return m[0][i-1];
        }
        if (h<1 || i<1)
            return 1000;
        int temp = 1000;
        for (int j=1; j<i; ++j)
            temp = min(temp, helper(j, h-1, mm, m) + m[j][i-1]);
        mm[i][h] = temp;
        return temp;
    }
};
