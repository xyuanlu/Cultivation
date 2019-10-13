/*
 * 265. Paint House II
 * There are a row of n houses, each house can be painted with one of the k colors.
 * The cost of painting each house with a certain color is different. You have to
 * paint all the houses such that no two adjacent houses have the same color.
 *
 * The cost of painting each house with a certain color is represented by a n x k
 * cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0;
 * costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.
 */
 
class Solution {
public:
    
    int minCostII(vector<vector<int>>& costs) {
        if (costs.size()==0)
            return 0;
        int M = costs.size(), N = costs[0].size();
        vector<vector<int>> m(M, vector<int>(N, INT_MAX));
        // Or we only need to remember the last 2 mins.
        multiset<int> t, tt;
        
        for(int j=0; j<N; ++j) {
            m[0][j] = costs[0][j];
            t.insert(m[0][j]);
        }
        
        for (int i=1; i<M; ++i) {
            for (int j=0; j<N; ++j) {
                t.erase(t.lower_bound(m[i-1][j]));
                m[i][j] = costs[i][j] + *(t.begin());
                tt.insert(m[i][j]);
                t.insert(m[i-1][j]);
                //cout<<m[i][j]<<" ";
            }
            //cout<<endl;
            t = tt;
            tt.clear();
        }
        
        int res = INT_MAX;
        
        for(int j=0; j<N; ++j) {
            res = min(m[M-1][j], res);
        }
        return res;
    }
};
