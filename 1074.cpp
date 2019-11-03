/*
 * 1074. Number of Submatrices That Sum to Target
 * Given a matrix, and a target, return the number of non-empty submatrices that sum to target.
 * 
 * A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.
 *
 * Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some
 * coordinate that is different: for example, if x1 != x1'.
 */
 
 class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        // sliding window + DP
        int M = matrix.size(), N = matrix[0].size();
        
        // 1. build th prefix sum matrix
        vector<vector<int>> m = vector<vector<int>>(M+1, vector<int>(N+1, 0));
        int temp = 0;
        for(int i=1; i<=matrix.size(); ++i) {
            m[i][1] = temp += matrix[i-1][0];
            //cout<<m[i][1]<<" ";
        }
        temp = 0;
        for(int i=1; i<=matrix[0].size(); ++i) {
            m[1][i] = temp += matrix[0][i-1];
            //cout<<m[1][i]<<" ";
        }
        
        for(int i=2; i<m.size(); ++i) {
            for(int j=2; j<m[0].size(); ++j) {
                m[i][j] = m[i-1][j] + m[i][j-1] - m[i-1][j-1]+matrix[i-1][j-1];
                //cout<<m[i][j]<<" ";
            }
            //cout<<endl;
        }
        
        int res = 0;
        /*
         * i: 0->n  j: i+1->n
         * for each row 0->m, compute (0, n), (k, j) and put it into map;
         * find if target - cur is in map
         */
        for (int i=1; i<=N; ++i) {
            for (int j=i; j<=N; ++j) {
                // value - count
                unordered_map<int, int> mm;
                //mm[0] = 1;
                for (int k=1; k<=M; ++k) {
                    int cur = m[k][j] - m[k][i-1];// - m[k-1][j] + m[k-1][i-1];
                    if(mm.find(cur-target) != mm.end()) {
                        res+=mm[cur-target];
                        //cout<<i<<" "<<j<<" "<<k<<" "<<cur<<endl;
                    }
                    if(cur == target) {
                        //cout<<i<<" "<<j<<" "<<k<<endl;
                        res ++;
                    }
                    //cout<<cur<<endl;
                    mm[cur]++;
                }
                //cout<<"*******"<<endl;
                
            }
        }
        return res;
    }
};

