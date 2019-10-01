/*
 * 746. Min Cost Climbing Stairs
 * On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).
 *
 * Once you pay the cost, you can either climb one or two steps. You need to find minimum
 * cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.
 */
 
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size()==0)
            return 0;
        vector<int> m(cost.size()+1, INT_MAX);
        m[0] = m[1] = 0;
        for(int i=2; i<=cost.size(); ++i) {
            m[i] = min((m[i-2]+cost[i-2]), (m[i-1]+cost[i-1]));
            //cout<<m[i]<<endl;
        }
        return m[cost.size()];
    }
};
