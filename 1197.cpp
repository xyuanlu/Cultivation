/*
 * 1197. Minimum Knight Moves
 */
 
class Solution {
public:
    class P{
    public:
        int x;
        int y;
        int step;
    };
    
    int minKnightMoves(int dstX, int dstY) {
        int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
        int dy[] = {-2, -1, 1, 2, -2, -1, 1, 2};
        
        if (dstX ==0 && dstY==0)
            return 0;
        
        queue<P> q;
        q.push({0, 0, 0});
        unordered_set<int> v;
        v.insert(0);
        
        while(!q.empty()) {
            P t = q.front();
            q.pop();
            int x = t.x;
            int y = t.y;
           // cout<<x<<" "<<y<<endl;
            //v.insert((x+300)*600+(y+300));
            //int d = 
            for(int i=0; i<8; ++i) {
                int xx = x+dx[i];
                int yy = y+dy[i];
                if (v.find((xx+300)*600+(yy+300))!=v.end()) {
                    continue;
                }
                if (xx==dstX && yy == dstY)
                    return t.step+1;
                 v.insert((xx+300)*600+(yy+300));
                //if (abs(xx-dstX)<abs(x-dstX) || abs(yy-dstY)<abs(y-dstY)) {
                    q.push({xx, yy, t.step+1});
                //}
            }
        }
        return -1;
        
    }
};
