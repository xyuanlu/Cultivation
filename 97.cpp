/*
 * 97. Interleaving String
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
 *
 * Example 1:
 *
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 * Output: true
 */
 
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size() + s2.size())
            return false;
        // matrix using s1 and s2. If we start from 0,0, can end at m, n
        
        int M = s1.size(), N = s2.size();
        // m[i][j] = true -> s3 befiore(i+j) an be formed using 
        // s1 before idx i and s2 before idx j 
        vector<vector<bool>> m(s1.size()+1, vector<bool>(s2.size()+1, false));
        
        m[0][0] = true;
        cout<<m[0][0]<<" ";
        for (int i=1; i<=s1.size(); ++i) {
            m[i][0] = m[i-1][0] && (s3[i-1] == s1[i-1]);
            
        }
        for (int j=1; j<=s2.size(); ++j) {
            m[0][j] = m[0][j-1] && (s3[j-1] == s2[j-1]);
            //cout<<m[0][j]<<" ";
        }
        //cout<<endl;
        
        for (int i=1; i<=M; ++i) {
            //cout<<m[i][0]<<" ";
            for (int j=1; j<=N; ++j) {
                if(s3[i+j-1] == s1[i-1] ){
                    m[i][j] = m[i][j]|| m[i-1][j] ;
                }
                if (s3[i+j-1] == s2[j-1]) {
                    m[i][j] = m[i][j] || m[i][j-1];
                }
                //cout<<m[i][j]<<" ";
            }
            //cout<<endl;
        }
        
        return m[M][N];
    }
};
