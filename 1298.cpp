/*
 * 1298. Maximum Candies You Can Get from Boxes
 */
 
 class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        // store reachble but unopened box
        vector<bool> unopened(status.size(), false);
        // a queue for next boxes we can open
        queue<int> q;
        // candies we have
        int res = 0;
        
        for(int i=0; i<initialBoxes.size(); ++i) {
            int cur = initialBoxes[i];
            if (status[cur] == 0) {
                unopened[cur] = true;
            } else {
                q.push(initialBoxes[i]);
            }
        }
        
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            //cout<<cur<<endl;
            res += candies[cur];
            for (int b:containedBoxes[cur]) {
                if (status[b] == 0){
                    //cout<<"B "<<b<<endl;
                    unopened[b] = true;
                } else {
                    q.push(b);
                }
            }
            for(int k:keys[cur]) {
                //cout<<"K "<<k<<endl;
                if (unopened[k]) {
                    q.push(k);
                    unopened[k] = false;
                } else {
                    status[k] = 1;
                }
            }
        }
        return res;
    }
};
