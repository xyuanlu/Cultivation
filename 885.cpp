/*
 * 885. Spiral Matrix III
 */
 
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        /*
         * Skip invalid i j pair.
         * Everytime we go k++ step;
         * Use a dx dy array for direction. 
         */
        // tighr, down, left, up
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        int k=1, x=r0, y=c0;
        vector<vector<int>> res{{r0, c0}};
        while(k<(C+R)*2){
            cout<<k<<endl;
            for(int d=0; d<4; ++d) {
                for(int i=0; i<k; ++i) {
                    x = x+dx[d];
                    y = y+dy[d];
                    //cout<<x<<" "<<y<<endl;
                    if(x>=0 && y>=0 && x<R && y<C) {
                        res.push_back(vector<int>({x, y}));
                        if(res.size() == R*C)
                            return res;
                    }

                }
                if(d==1) ++k;
            }
            ++k;
        }
        
        return res;
        
    }
};
