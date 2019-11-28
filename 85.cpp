/*
 * 85. Maximal Rectangle
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
 */
 
class Solution {
public:
     // compute all rectangles ends at matrix[i][j]
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size()==0)
            return 0;
        //m[i][j] continous 1's on the same line, left of i, j
        vector<vector<int>> m(matrix.size(), vector<int>(matrix[0].size(), 0));
        int res = 0;
        for (int i=0; i<matrix.size(); ++i) {
            if (matrix[i][0]=='1')
                m[i][0] = 1;
        }
        
        for (int i=0; i<matrix.size(); ++i) {
            for(int j=1; j<matrix[0].size(); ++j) {
                if(matrix[i][j] == '1') {
                    m[i][j] = m[i][j-1]+1;
                }
                //cout<<m[i][j]<<" ";
            }
            //cout<<endl;
        }
        
        for (int i=0; i<matrix.size(); ++i) {
            for(int j=0; j<matrix[0].size(); ++j) {
                if(m[i][j] >0) {
                    // go from i, j -> i, 0
                    int w = m[i][j];
                    cout<<w<<endl;
                    for (int k=i; k>=0; --k) {
                        w = min(w, m[k][j]);
                        //cout<<w<<" "<<(i-k+1)*w<<endl;
                        res = max(res, (i-k+1)*w);
                    }
                }
            }
        }
        
        return res;
    }
    

};
