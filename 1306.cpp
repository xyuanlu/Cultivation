/*
 * 1306. Jump Game III
 * Given an array of non-negative integers arr, you are initially positioned at start index of
 * the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.
 *
 * Notice that you can not jump outside of the array at any time.
 */
 
 // BFS
 class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        visited[start] = true;
        queue<int> q;
        q.push(start);
        
        while(!q.empty()) {
            int t = q.front();
            q.pop();
            if (arr[t] ==0)
                return true;
            for(int i=t-arr[t]; i<=t+arr[t]; i+=(arr[t]*2) ) {
                if (i<0) continue;
                if (i>=arr.size()) break;
                if (visited[i]) continue;
                //cout<<t<<"->"<<i<<endl;
                q.push(i);
                visited[i] = true;
            }
        }
        return false;
    }
};
