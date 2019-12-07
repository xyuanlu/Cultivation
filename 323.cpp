/*
 * 323. Number of Connected Components in an Undirected Graph
 */
 
 class Solution {
public:
    class UF{
    private:
        int N;
        vector<int> unions;
        vector<int> size;
    public:
        UF(int n) {
            N = n;
            for(int i=0; i<n; ++i) {
                unions.push_back(i);
                size.push_back(i);
            }
        }
        
        int findParent(int a) {
            int p = unions[a];
            int res = p;
            if (p!=a) {
                res = findParent(p);
                unions[p] = res;
            }
            return res;
        }
        
        bool isUnited(int a, int b) {
            return findParent(a) == findParent(b);
        }
        
        void unite(int a, int b) {
            int aa = findParent(a);
            int bb = findParent(b);
            if (aa == bb) return;
            if (size[aa]<size[bb]) {
                unions[aa] = bb;
                size[bb] += size[aa];
            } else {
                unions[bb] = aa;
                size[aa] += size[bb];
            }
            N--;
            cout<<N<<endl;
        } 
        
        int unionSize(){
            return N;
        }
        
    };
    
    int countComponents(int n, vector<vector<int>>& edges) {
        UF uf(n);
        for(int i=0; i<edges.size(); ++i) {
            cout<<edges[i][0]<<" "<<edges[i][1]<<endl;
            uf.unite(edges[i][0], edges[i][1]);
        }
        return uf.unionSize();
    }
};







