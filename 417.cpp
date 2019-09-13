/*
 * 417. Pacific Atlantic Water Flow
 *
 * Given an m x n matrix of non-negative integers representing the height of each unit
 * cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix
 * and the "Atlantic ocean" touches the right and bottom edges.
 *
 * Water can only flow in four directions (up, down, left, or right) from a cell to another
 * one with height equal or lower.
 *
 * Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.
 */
 
 class Solution {
public:

    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        if(matrix.size() == 0)
            return res;
        int m=matrix.size(), n = matrix[0].size();
        vector<vector<bool>> p(m, vector<bool>(n, false));
        vector<vector<bool>> a(m, vector<bool>(n, false));
        
        for(int i=0; i<m; ++i) helper(i, 0, p, matrix);
        
        for(int i=0; i<n; ++i) helper(0, i, p, matrix);
        
        for(int i=0; i<m; ++i) helper(i, n-1, a, matrix);
        
        for(int i=0; i<n; ++i) helper(m-1, i, a, matrix);
        
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(p[i][j] && a[i][j]) {
                       res.push_back(vector<int> {i, j});
                }
            }
        }
        return res;
    }
    
    bool isValid(int x, int y, int xx, int yy, const vector<vector<int>>& m) {
        if(xx<0 || xx>=m.size() || yy<0 || yy>=m[0].size())
            return false;
        if(m[xx][yy] < m[x][y])
            return false;
        return true;
    }
        
    void helper(int x, int y, vector<vector<bool>>& visited, 
                const vector<vector<int>>& matrix) {
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        
        if(visited[x][y])
            return;
        //cout<<x<<" "<<y<<endl;
        visited[x][y] = true;
        for(int d=0; d<4; ++d) {
            int xx = x + dx[d];
            int yy = y + dy[d];
            if(!isValid(x, y, xx, yy, matrix))
                continue;
            helper(xx, yy, visited, matrix);
        }
        
    }
        
        
        
        
        
};
