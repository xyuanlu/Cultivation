/*
 * 1284. Minimum Number of Flips to Convert Binary Matrix to Zero Matrix
 * Given a m x n binary matrix mat. In one step, you can choose one cell and flip it and all the four neighbours of
 * it if they exist (Flip is changing 1 to 0 and 0 to 1). A pair of cells are called neighboors if they share one edge.
 *
 * Return the minimum number of steps required to convert mat to a zero matrix or -1 if you cannot.
 *
 * Binary matrix is a matrix with all cells equal to 0 or 1 only.
 *
 * Zero matrix is a matrix with all cells equal to 0.
 */
 

class Solution {
public:
    class P{
    public:
        int n;
        int l;
    };
    
    int M;
    int N;
    
    int minFlips(vector<vector<int>>& mat) {

        M  = mat.size();
        N = mat[0].size();
        int target = 0;
        int num = 0;
        
        for(int i=0; i<M; ++i) {
            for(int j=0; j<N; ++j) {
                if (mat[i][j] == 1) {
                    num = num | (1 << (i*N+j));
                    cout<<num<<endl;
                }
            }
        }
        if (num==0)
            return 0;
        queue<P> q;
        q.push({num, 0});
        unordered_set<int> visited;
        visited.insert(num);
        // flip the l-th bit means num = num ^ (i<<l)
        while(!q.empty()) {
            P t = q.front();
            //cout<<"- " <<t.n<<endl;
            q.pop();
            for(int i=0; i<M; ++i) {
                for(int j=0; j<N; ++j) {
                    int nn = flipBit(t.n, i, j);
                    if (visited.find(nn)!=visited.end()) {
                        continue;
                    }
                    //cout<<nn<<endl;
                    if (nn == target) {
                        return t.l+1;
                    }
                    visited.insert(nn);
                    q.push({nn, t.l+1});
                }
            }
        }
        
        return -1;
    }
    
    // flip all 4 dirctions of te bit
    int flipBit(int n, int i, int j) {
        int dx[] = {0, -1, 1, 0, 0};
        int dy[] = {0, 0, 0, 1, -1};
        for(int d=0; d<5; ++d) {
            int x = i+dx[d];
            int y = j+dy[d];
            if (x>=0 && y>=0 && x<M && y<N) {
                //cout<<x<<" "<<y;
                n = n ^ (1<<x*N+y); 
            }
        }
        return n;
    }
};

