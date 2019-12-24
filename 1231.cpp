/*
 * 1231. Divide Chocolate
 * You have one chocolate bar that consists of some chunks. Each chunk has its own sweetness given by the array sweetness.
 *
 * You want to share the chocolate with your K friends so you start cutting the chocolate bar into K+1 pieces using
 * K cuts, each piece consists of some consecutive chunks.
 *
 * Being generous, you will eat the piece with the minimum total sweetness and give the other pieces to your friends.
 * 
 * Find the maximum total sweetness of the piece you can get by cutting the chocolate bar optimally.
 */
 
 class Solution {
public:
    // Binary search
    int maximizeSweetness(vector<int>& sweetness, int K) {
        // min -> max T T F F
        // min is min in array, max is max+1
        int l=INT_MAX;
        long long r = 0;
        for(int i:sweetness) {
            l = min(i, l);
            r = r+i;
        }
        if (K==0)
            return r;
        r = r/K +1;
        int m;
        //cout<<l<<" "<<r<<endl;
        while(r>l+1) {
            m = l + (r-l)/2;
            if (canDo(m, sweetness, K+1)) {
                l = m;
            }
            else {
                r = m;
            }
        }
        return l;
    }
    
    bool canDo(int m, vector<int>& sweetness, int K) {
        int sum = 0;
        int k=0;
        for(int i:sweetness) {
            sum+=i;
            if(sum>=m) {
                sum = 0;
                k++;
                if (k==K)
                    return true;
            }
        }
        return k>=K;
    }
};
