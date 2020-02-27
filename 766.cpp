/*
* 766. Toeplitz Matrix
*/

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int M = matrix.size(), N = matrix[0].size();
        for(int d=0; d<N; ++d) {
            int x=0, y=d;
            int t = matrix[0][d];
            while(x<M && y<N) {
                if (matrix[x][y] != t)
                    return false;
                ++x;
                ++y;
            }   
        }
        
        for(int d=1; d<M; ++d) {
            int x=d, y=0;
            int t = matrix[d][0];
            while(x<M && y<N) {
                if (matrix[x][y] != t)
                    return false;
                ++x;
                ++y;
            }   
        }
        return true;
        
    }
};
