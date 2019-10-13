/*
 * 739. Daily Temperatures
 * Given a list of daily temperatures T, return a list such that, for each day in the
 * input, tells you how many days you would have to wait until a warmer temperature.
 * If there is no future day for which this is possible, put 0 instead.
 */
 
/*
 * Similar to many problem. If we want to find a certain pattern in a list. 
 * Iterate from end and maintain a monotonic stack
 */
 
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        // find the first number larger than current number
        // Iterate from right to left, keep an increasing stack.
        // top of ths stack will be the most recent warmer temperature
        
        stack<pair<int, int>> m;
        int idx = T.size()-1;
        vector<int> res(T.size());
        
        for(int i=T.size()-1; i>=0; --i) {
            while (m.size()!=0 && m.top().first<=T[i]) {
                m.pop();
            }
            if (m.size()>0) {
                res[i] = m.top().second-i;
            }
            if (m.size()==0) {
                res[i] = 0;  
            }
            m.push(make_pair(T[i], i));
        }
        
        return res;
    }
};
