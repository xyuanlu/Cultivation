/*
 * 1102. Path With Maximum Minimum Value
 * Given a matrix of integers A with R rows and C columns, find the maximum score of a
 * path starting at [0,0] and ending at [R-1,C-1].
 *
 * The score of a path is the minimum value in that path.  For example, the
 * value of the path 8 →  4 →  5 →  9 is 4.
 *
 * A path moves some number of times from one visited cell to any neighbouring unvisited
 * cell in one of the 4 cardinal directions (north, east, west, south).
 */
 
 class Solution {
public:
    class P {
    public:
        int x;
        int y;
        int val;
        
        bool operator<(P &pp) const{
            return val < pp.val;
        }
        
    };
    
    class UF{
    public:
        UF(){;}
        UF(int n) {
            for(int i=0; i<n; ++i) {
                parents.push_back(i);
                count.push_back(1);
            }
        }
        
        int findParent(int n) {
            int p = parents[n];
            if (p!=n) {
                p = findParent(p);
            }
            parents[n] = p;
            return p;
        }
        
        void unite(int a, int b) {
            int aa = findParent(a);
            int bb = findParent(b);
            if (aa == bb)
                return;
            //cout<<count[aa]<<" "<<count[bb]<<endl;
            if (count[aa] > count[bb]) {
                parents[bb] = aa;
                count[aa] += count[bb];
            } else {
                parents[aa] = bb;
                count[bb] += count[aa];
            }
        }
        
        bool isUnited(int a, int b) {
            return findParent(a) == findParent(b);
        }
        
    private:
        vector<int> parents;
        vector<int> count;
    };
    
    /*
     * Adding nodes to the path from latgest to min untill begin and end meets.
     * Use union find to determin if they meet.
     */
    
    int maximumMinimumPath(vector<vector<int>>& A) {
        M = A.size();
        N = A[0].size();
        
        vector<P> sortedNodes;
        visited = vector<vector<bool>>(M, vector<bool>(N, false));
        uf = UF(M*N);
        
        
        for(int i=0; i<M; ++i) {
            for (int j=0; j<N; ++j) {
                sortedNodes.push_back({i, j, A[i][j]});
            }
        }
        sort(sortedNodes.begin(), sortedNodes.end());
        int res = INT_MAX;
        
        while(!uf.isUnited(0, M*N-1)) {
            P t = sortedNodes.back();
            sortedNodes.pop_back();
            res = t.val;
            
            combine(t);
        }
        
        return res;
    }
    
    void combine(P& p) {
        int x = p.x;
        int y = p.y;
        visited[x][y] = true;
        //cout<<x*N+y<<endl;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        
        for(int d=0; d<4; ++d) {
            int xx = x+dx[d];
            int yy = y+dy[d];
            if (xx>=0 && yy>=0 && xx<M && yy<N && visited[xx][yy]) {
                uf.unite(x*N+y, xx*N+yy);
            }
        }
    }
    
    vector<vector<bool>> visited;
    UF uf;
    int M, N;
};
