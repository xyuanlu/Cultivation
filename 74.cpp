/*
 * 74. Search a 2D Matrix
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 *
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int t) {
        // Find the last row that the first number <= target
        //  T, T, F, F
        if (matrix.size()==0 || matrix[0].size() ==0 ||t<matrix[0][0])
            return false;
        int l=0, r=matrix.size(), m=l;
        int row = 0, line = 0;
        while (r-l>1) {
            m = l+(r-l)/2;
            //cout<<m<<endl;
            if (matrix[m][0]<=t) {
                l = m;
            } else {
                r = m;
            }
        }
        row = l;
        //cout<<l<<endl;
        // in the row, find the target
        l = 0, r=matrix[0].size(), m=l;
        while(r-l>1) {
            m = l+(r-l)/2;
            if (matrix[row][m]<=t) {
                l = m;
            } else {
                r=m;
            }
        }
        return matrix[row][l] == t;
    }
};
