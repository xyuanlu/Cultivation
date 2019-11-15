/*
 * 710. Random Pick with Blacklist
 * Given a blacklist B containing unique integers from [0, N), write a function to return a uniform random integer from [0, N) which is NOT in B.
 *
 * Optimize it such that it minimizes the call to system’s Math.random().
 */
 
class Solution {
public:
    unordered_map<int, int> m;
    int K;
    Solution(int N, vector<int>& blacklist) {
        // use two pointer to find the map between numebr
        // in black list to white list
        sort(blacklist.begin(), blacklist.end());
        K = N-blacklist.size();
        int bl = 0, n = N-1, bidx = blacklist.size()-1;
        while(bl<blacklist.size() && blacklist[bl] < n) {
            if (bidx>=0 && n == blacklist[bidx]) {
                bidx--;
                n--;
                continue;
            }
            m[blacklist[bl]] = n;
            //cout<<blacklist[bl]<<" "<<n<<endl;
            n--;
            bl++;
        }
    }
    
    int pick() {
        int x = std::rand()%K;
        if(m.find(x)!=m.end()) {
            return m[x];
        }
        else
            return x;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */
