/*
 *  311. Sparse Matrix Multiplication
 *      Runtime: 12 ms, faster than 72.18% of C++ online submissions for Sparse Matrix Multiplication.
 */


class Solution {
public:
    /*  
     *  A: i(row)*j(colume), B:j*h , res: i*h  
     */
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res(A.size(), vector<int>(B[0].size(), 0));
        if(A.size()==0)
            return res;
        
        // A vector of map of each colume in B. key is idx value is value
        vector<unordered_map<int, int>> b(B[0].size());
        for(int h=0; h<B[0].size(); ++h) {
            for(int j=0; j<B.size(); ++j) {
                if(B[j][h] !=0)
                    b[h][j] = B[j][h];
            }
        }

        for(int i=0; i<A.size(); ++i) {
            for(int h=0; h<b.size(); ++h) {
                int temp = 0;
                for (auto it:b[h]) {     
                    //cout<<"i: "<<i<<" "<<it.first<<endl;
                    if(A[i][it.first] != 0) {
                        
                        temp += A[i][it.first] * it.second;
                    }
                }
                //cout<<"res"<<i<<" "<<h<<" "<<temp<<endl;
                res[i][h] = temp;
            } 
        }
        
        return res;
    }
};
