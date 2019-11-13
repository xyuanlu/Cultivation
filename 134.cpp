/*
 * 134. Gas Station
 */
 
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int res=0, cur = 0, tot = 0;
        for(int i=0; i<gas.size(); ++i) {
            tot += gas[i] - cost[i];
            cur += gas[i] - cost[i];
            if (cur<0) {
                res = i+1;
                cur = 0;
            }
        }
        return tot<0? -1: res;
    }
};
