/*
 * 361. Bomb Enemy
 * Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0'
 * (the number zero), return the maximum enemies you can kill using one bomb.
 * The bomb kills all the enemies in the same row and column from the planted
 * point until it hits the wall since the wall is too strong to be destroyed.
 * Note: You can only put the bomb at an empty cell.
 */
 
 class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int res = 0;
        if(grid.size()==0) return 0;
        int m=grid.size(), n=grid[0].size();
        //upper, left, right, down
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(4, 0)));
        
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(grid[i][j] == 'W')
                    continue;
                if(i>0){
                    memo[i][j][0]+=memo[i-1][j][0];
                }
                if(j>0) {
                    memo[i][j][1]+=memo[i][j-1][1];
                }
                if(grid[i][j] == 'E') {
                    memo[i][j][0]++;
                    memo[i][j][1]++;
                }
            }
        }
        
        for(int i=m-1; i>=0; --i) {
            for(int j=n-1; j>=0; --j) {
                if(grid[i][j] == 'W')
                    continue;
                if(i<m-1){
                    memo[i][j][3]+=memo[i+1][j][3];
                }
                if(j<n-1) {
                    memo[i][j][2]+=memo[i][j+1][2];
                }
                int temp=0;
                for(auto it : memo[i][j])
                    temp += it;
                //cout<<temp<<" ";
                if(grid[i][j] != 'E')
                    res = max(res, temp);
                if(grid[i][j] == 'E') {
                    memo[i][j][2]++;
                    memo[i][j][3]++;
                }
            }
            //cout<<endl;
        }
        
        return res;
    }
};
