/*
 * 240. Search a 2D Matrix II
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 *
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 */
 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // search space reduction. start from bottom left corner
        if (matrix.size()==0)
            return false;
        
        int x = matrix.size()-1, y=0;
        while (x>=0 && y<matrix[0].size()) {
            if (matrix[x][y] == target) {
                return true;
            }
            if (matrix[x][y] < target) {
                y++;
                continue;
            }
            if (matrix[x][y] > target) {
                x--;
                continue;
            }
        }
        return false;
        
    }
};
