/*
 * 1319. Number of Operations to Make Network Connected
 */
 
 class Solution {
public:
    class UF{
    public:
        UF(int n) {
            k = n;
            parent = vector<int>(n);
            size = vector<int>(n);
            for(int i=0; i<n; ++i) {
                parent[i] = i;
                size[i] = 1;
            }
        }
        
        int getParent(int n) {
            int p = parent[n];
            if (p!=n) {
                p = getParent(p);
            }
            parent[n] = p;
            return p;
        }
        
        bool isUnited(int a, int b) {
            return getParent(a) == getParent(b);
        }
        
        int numUnions() {return k;}
        
        void unite(int a, int b) {
            int aa = getParent(a);
            int bb = getParent(b);
            if (aa == bb) {return;}
            if (size [aa]< size[bb]) {
                parent[aa] = bb;
                size[bb]+=size[aa];
            } else {
                parent[bb] = aa;
                size[aa]+=size[bb];
            }
            k--;
        }
        
        
    private:
        vector<int> parent;
        vector<int> size;
        int k;
    };
    
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        UF uf(n);
        for(int i=0; i<connections.size(); ++i) {
            uf.unite(connections[i][0], connections[i][1]);
        }
        
        int subNet = uf.numUnions();
        // number of edge ca not be removed id the #node - #group
        if (connections.size()-(n-subNet) < subNet-1) /*extra < needed*/ 
              {return -1;}
        
        return subNet-1;
        
    }
};
