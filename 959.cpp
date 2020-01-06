/*
 * 959. Regions Cut By Slashes
 * In a N x N grid composed of 1 x 1 squares, each 1 x 1 square consists
 * of a /, \, or blank space.  These characters divide the square into contiguous regions.
 *
 * (Note that backslash characters are escaped, so a \ is represented as "\\".)
 *
 * Return the number of regions.
 */
 
 class Solution {
public:
    /*
     * Devide each block into 4 sub blocks and use ynion find
     *  \ 1 /
     *  0\ /2
     *   /3\
     *  /   \
     * Each subblock is (i*M+j)*4 + k 
     */
    class UF{
    public:
        UF(){;}
        
        UF(int n) {
            N = n;
            count = vector<int>(n, 1);
            for(int i=0; i<n; ++i) {
                parents.push_back(i);
            }
        }
        
        int findParent(int n) {
            int p = parents[n];
            if (p != n) {
                p = findParent(p);
                parents[n] = p;
            }
            return p;
        }
        
        bool isUnited(int a, int b) {
            return findParent(a) == findParent(b);
        }
        
        void unit(int a, int b) {
            int aa = findParent(a);
            int bb = findParent(b);
            if (aa == bb) return;
            N--;
            // add the smaller group into the larger
            //cout<<"unite "<<a<<" "<<b<<endl;
            if (count[aa]<count[bb]) {
                parents[aa] = bb;
                count[bb]+=aa;
            } else {
                parents[bb] = aa;
                count[aa]+=bb;
            }
        }
        
        int size(){
            return N;
        }
        
        
    private:
        int N;
        vector<int> parents;
        vector<int> count;
    };
    
    
    int regionsBySlashes(vector<string>& grid) {
        M = grid.size();
        
        uf = UF(M*M*4);
        
        for(int i=0; i<M; ++i) {
            for(int j=0; j<M; ++j) {
                unitPrev(i,j);
            }
        }
        
        for(int i=0; i<M; ++i) {
            for(int j=0; j<M; ++j) {
                int idx = (i*M+j)*4;
                //cout<<idx<<endl;
                if (grid[i][j] == ' ') {
                    uf.unit(idx, idx+1);
                    uf.unit(idx+1, idx+2);
                    uf.unit(idx+2, idx+3);
                } else if (grid[i][j] == '/') {
                    uf.unit(idx, idx+1);
                    uf.unit(idx+2, idx+3);
                } else {  // '\'
                    uf.unit(idx+2, idx+1);
                    uf.unit(idx+0, idx+3);
                }
            }
        }
        
        return uf.size();
    }
    
    void unitPrev(int i, int j) {
        // unite 1 and previous 3
        if (i>0) {
            int a = (i*M+j)*4+1;
            int b = ((i-1)*M+j)*4+3;
            //cout<<"1: "<<a<<" "<<b<<endl;
            uf.unit(a, b);
        }
        // 0 with left 2
        if (j>0) {
            int a = (i*M+j)*4;
            int b = (i*M+(j-1))*4+2;
            //cout<<"2: "<<a<<" "<<b<<endl;
            uf.unit(a, b);
        }
    }
    
    int M;
    UF uf;
};
