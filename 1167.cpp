/*
 * 1167. Minimum Cost to Connect Sticks
 * You have some sticks with positive integer lengths.
 * You can connect any two sticks of lengths X and Y into one stick
 * by paying a cost of X + Y.  You perform this action until there is one stick remaining.
 *
 * Return the minimum cost of connecting all the given sticks into one stick in this way.
 */
 
class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        int res = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i=0; i<sticks.size(); ++i) {
            pq.push(sticks[i]);
        }
        
        while(pq.size()>=2) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            pq.push(a+b);
            //cout<<a+b<<endl;
            res += a+b;
        }
        
        //res+=pq.top();
        
        return res;
    }
};
