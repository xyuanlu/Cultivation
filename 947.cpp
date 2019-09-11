/*
 * 947. Most Stones Removed with Same Row or Column
 *  On a 2D plane, we place stones at some integer coordinate points. 
 *  Each coordinate point may have at most one stone.
 *
 *  Now, a move consists of removing a stone that shares a column or row with another stone on the grid.
 *
 *  What is the largest possible number of moves we can make?
 *
 *  [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]] -> 5
 *  [[0,0],[0,2],[1,1],[2,0],[2,2]] -> 3
 */

class Solution {
public:
    class UnionFind{
    public:
        vector<int> uni;
        vector<int> size;
        int N;
        
        UnionFind(int n) {
            N = n;
            for(int i=0; i<n; ++i) {
                uni.push_back(i);
                size.push_back(1);
            }
        }
        
        int GetParent(int a) {
            int res = uni[a];
            if(res != a) {
                res = GetParent(uni[a]);
            }
            uni[a] = res;
            return res;
        }
        
        bool IsUnited(int a, int b) {
            return GetParent(a) == GetParent(b);
        }
        
        void Unite(int a, int b) {
            int aa = GetParent(a), bb = GetParent(b);
            cout<<"unit"<<a<<" "<<aa<<" "<<b<<" "<<bb<<endl;;
            
            if(aa == bb) {
                return;
            }
           
            //cout<<"p: "<<aa<<" "<<bb<<endl;
            if(size[aa] >= size[bb]) {
                uni[bb] = aa;
                size[aa] += size[bb];
            } else {
                uni[aa] = bb;
                size[bb] += size[aa];
            }
        }
        
    };
    int removeStones(vector<vector<int>>& stones) {
        /*
         *  Union Find
         *      If two nodes shares a line or colume. They can be united.
         *      For each union, we can remove unionsize()-1 nodes.
         */
        UnionFind uf(stones.size());
        int res = 0;
        // key is the row or colume number, value is the last element's idx in the row/colume
        unordered_map<int, int> c, r;
        for(int i=0; i<stones.size(); ++i) {
            if(c.find(stones[i][0]) == c.end()) {
                c[stones[i][0]] = i;
            } else {
                uf.Unite(i,  c[stones[i][0]]);
            }
            
            if(r.find(stones[i][1]) == r.end()) {
                r[stones[i][1]] = i;
            } else {
                uf.Unite(i,  r[stones[i][1]]);
            }
        }
        
        for(int i=0; i<uf.N; ++i) {
            cout<<i<<" "<<uf.uni[i]<<endl;
            if(i == uf.uni[i]) {
                res += uf.size[i]-1;
            }
        }
        return res;
    }
}; 


