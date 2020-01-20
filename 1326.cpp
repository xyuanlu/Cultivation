/*
 * 1326. Minimum Number of Taps to Open to Water a Garden
 */
 
 class Solution {
public:
    class P{
    public:
        int l;
        int r;
        
        // priority queue sort from large to small
        bool operator<(const P &p) const {
            if (l == p.l) {
                return r < p.r;
            }
            else {
                return l > p.l;
            }
        }
    };
    int minTaps(int n, vector<int>& ranges) {
        priority_queue<P> pq;
        for(int i=0; i<ranges.size(); ++i) {
            if (ranges[i] ==0)
                continue;
            int l = max(0, i-ranges[i]);
            int r = i+ranges[i];
            //cout<<l<<" "<<r<<endl;
            pq.push({l, r});
        }
        
        
        if (pq.size()==0 || pq.top().l!=0)
            return -1;
        int maxR = 0;
        int nextR = maxR;
        int res = 0;
        while(pq.size()!=0 && pq.top().l<=maxR) {
            nextR = max(nextR, pq.top().r);
            if (nextR>=n)
                return res+1;
            pq.pop();
            if (!pq.empty() &&pq.top().l>maxR) {
                res++;
                maxR = nextR;;
            }
        }
        //cout<<"XX"<<endl;
        return -1;
    }
};
