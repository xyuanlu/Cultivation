/*
 * 221. Maximal Square
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
 */
 
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // num of 1s up and num of 1s on its left, including self
        int res = 0;
        if(matrix.size()==0) return 0;
        int m = matrix.size(), n=matrix[0].size();
        //vector<vector<vector<int>>> tracker(m, vector<vector<int>>(n, vector<int>(2, 0)));
        vector<vector<int>> memo(m, vector<int>(n, 0));
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(matrix[i][j] == '1') {
                    //tracker[i][j][0] = 1;
                    //tracker[i][j][1] = 1;
                    if(i==0 || j==0) {
                        memo[i][j] = 1;
                    } else {
                        memo[i][j] = min(memo[i-1][j], min(memo[i][j-1], memo[i-1][j-1]))+1;
                    }
                    res = max(res, memo[i][j]);
                }
                //cout<<memo[i][j]<<" ";
            }
            //cout<<endl;
        }
        return res*res;
    }
};
