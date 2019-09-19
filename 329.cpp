/*
 * 329. Longest Increasing Path in a Matrix
 * 
 * Given an integer matrix, find the length of the longest increasing path.
 *
 * From each cell, you can either move to four directions: left, right,
 * up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).
 */
 
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size()==0)
            return 0;
        int M=matrix.size(), N=matrix[0].size();
        // Search and remember
        // m[i][j] : starting from i, j what is the max increasing path
        vector<vector<int>> m(M, vector<int>(N, -1));
        int res = 1;
        for(int i=0; i<M; ++i) {
            for(int j=0; j<N; ++j) {
                if (m[i][j] == -1) {
                    helper(matrix, m, i, j);
                }
                res = max(res, m[i][j]);
            }
        }
        /*for(int i=0; i<M; ++i) {
            for(int j=0; j<N; ++j) {
                cout<<m[i][j]<<" ";
            }
            cout<<endl;
        }*/
        return res;
    }
    
    int helper(const vector<vector<int>>& matrix, vector<vector<int>>& m,
                int x, int y) {
        int dx[] = {1, 0, 0, -1};
        int dy[] = {0, 1, -1, 0};
        if (x<0 || y<0 || x>=matrix.size() || y>= matrix[0].size())
            0;
        if (m[x][y] != -1) {
            return m[x][y];
        }
        int temp = 1;
        for(int i=0; i<4; ++i) {
            int xx = x+dx[i];
            int yy = y+dy[i];
            if(xx>=0 && yy>=0 && xx<matrix.size() && yy< matrix[0].size() 
               && matrix[x][y]<matrix[xx][yy]) {
                temp = max(temp, 1+helper(matrix, m, xx, yy));
            }
        }
        m[x][y] = temp;
        //cout<<x<<" "<<y<<" "<<m[x][y]<<endl;
        return temp;
    }
};
