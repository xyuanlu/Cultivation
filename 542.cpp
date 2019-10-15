/*
 * 542. 01 Matrix
 * Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
 *
 * The distance between two adjacent cells is 1.
 */
 
class Solution {
public:
    class P{
    public:
        int x;
        int y;
        int d;
        
        P(int xx, int yy, int dd) : x(xx), y(yy), d(dd) {};
    };
    
    // Similar to "317 shortest distance from all building"
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int M = matrix.size(), N = matrix[0].size();
        vector<vector<int>> res(M, vector<int>(N, INT_MAX));
        vector<vector<int>> visited(M, vector<int>(N, false));
        queue<P> q;
        
        
        for (int i=0; i<M; ++i) {
            for (int j=0; j<N; ++j) {
                if (matrix[i][j] == 0) {
                    res[i][j] = 0;
                    q.push(P(i, j, 0));
                    visited[i][j] = true;
                }
            }
        }
        
        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, 1, -1, 0};
        
        while(!q.empty()) {
            P t = q.front();
            q.pop();
            visited[t.x][t.y] = true;
            if (matrix[t.x][t.y] == 1) {
                res[t.x][t.y] = min(res[t.x][t.y], t.d);   // <<<<<-------
            }
            int xx, yy;
            for (int k=0; k<4; ++k) {
                xx = t.x+dx[k];
                yy = t.y+dy[k];
                if (xx>=0 && yy>=0 && xx<M && yy<N && !visited[xx][yy]) {
                    //cout<<xx<<" "<<yy<<endl;
                    q.push(P(xx, yy, t.d+1));
                }
            }
        }
        
        return res;
    }
};
