/*
 * 498. Diagonal Traverse
 * Given a matrix of M x N elements (M rows, N columns), return all elements of
 * the matrix in diagonal order as shown in the below image.
 */
 
 class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        vector<int> temp;
        if (matrix.size() == 0 ) return res;
        int m=matrix.size(), n=matrix[0].size();
        res.reserve(m+n-1);
        for (int k=0; k<m+n-1; ++k) {
            for (int i=0; i<m; ++i) {
                int j=k-i;
                if (j>=n || j<0) continue;
                //cout<<i<<" "<<j<<endl;
                temp.push_back(matrix[i][j]);
            }
            if (k%2 == 0) {
                reverse(temp.begin(), temp.end());
            }
            res.insert(res.end(), temp.begin(), temp.end());
            temp.clear();
        }
        return res;
    }
};
