/*
 * 304. Range Sum Query 2D - Immutable
 *
 * Given a 2D matrix matrix, find the sum of the elements inside the rectangle
 * defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
 *
 */
 
 class NumMatrix {
public:
    // memo[i][j] = the sum of rectangle from (0,0) to (i, j) including i, j
    vector<vector<int>> memo;
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() ==0)
            return;
        int M = matrix.size(), N = matrix[0].size();
        memo.push_back(vector<int>(N+1, 0));
        for(int i=0; i<M; ++i) {
            vector<int> t = {0};
            int sum = 0;
            for(int j=0; j<N; ++j) {
                //cout<<matrix[i][j] <<"+"<<t.back()<<"+"<<memo[i][j+1]<<" ";
                sum+=matrix[i][j];                            <------- XXX
                t.push_back(sum + memo[i][j+1]);
            }
            //cout<<endl;
            memo.push_back(t);
        }
        /*for(int i=0; i<=M; ++i) {
            for(int j=0; j<=N; ++j) {
                cout<<memo[i][j]<<" ";
            }
            cout<<endl;
        }*/
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return memo[row2+1][col2+1]
                - (memo[row1][col2+1] + memo[row2+1][col1])     <------- XXX
                + memo[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
