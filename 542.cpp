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
    
    
   // Similar to 361. Bomb Enemy
   vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int M = matrix.size(), N = matrix[0].size();
        vector<vector<int>> m(M, vector<int>(N, 100000000));
        //vector<vector<int>> m2(M, vector<int>(N, 100000000));
       
        for (int i=0; i<M; ++i) {
            for (int j=0; j<N; ++j) {
                if (matrix[i][j] ==0) {
                    m[i][j] =0;
                } else {
                    if (i>0)
                        m[i][j] = min(m[i][j], m[i-1][j]+1);
                    if (j>0)
                         m[i][j] = min(m[i][j], m[i][j-1]+1);
                }
            }
        }
       
       for (int i=M-1; i>=0; --i) {
            for (int j=N-1; j>=0; --j) {
                if (matrix[i][j] == 0) {
                    m[i][j] =0;
                } else {
                    if (i<M-1)
                        m[i][j] = min(m[i][j], m[i+1][j]+1);
                    if (j<N-1)
                        m[i][j] = min(m[i][j], m[i][j+1]+1);
                }
                //m1[i][j] = min(m1[i][j], m2[i][j]);
            }
        }
       
       return m;
        
    }
    
    
    // Similar to "317 shortest distance from all building"
    vector<vector<int>> updateMatrix2(vector<vector<int>>& matrix) {
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
            
            // If we are pooping level by level (adding new element to qq and swap when q is empty)
            // It is ok to set the visited here and update res. 
            // Since res need to be updated level by level.
            // Thus, we do it in the for loop since we only have one queue
            
            int xx, yy;
            for (int k=0; k<4; ++k) {
                xx = t.x+dx[k];
                yy = t.y+dy[k];
                if (xx>=0 && yy>=0 && xx<M && yy<N && !visited[xx][yy]) {
                    //cout<<xx<<" "<<yy<<endl;
                    visited[xx][yy] = true;
                    res[xx][yy] = t.d+1; //min(res[t.x][t.y], t.d);   // <<<<<-------
                    
                    q.push(P(xx, yy, t.d+1));
                }
            }
        }
        
        return res;
    }
};
