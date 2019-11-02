/*
 * 1011. Capacity To Ship Packages Within D Days
 */
 
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int sum = 0, max = 0;
        for (int i:weights) {
            sum += i;
            max = std::max(i, max);
        }
        int l = max-1, r = sum, m;
        //cout<<max<<" "<<r<<endl;
        // F F T T  
        while (r>l+1) {
            m = l + (r-l)/2;
            //cout<<m<<endl;
            if (doable(weights, D, m)) {
                r = m;
            } else {
                l = m;
            }
        }
        return r;
    }
    
    bool doable (vector<int>& weights, int D, int m) {
        int count = 1, cur = 0;
        for (int i:weights) {
            if (cur+i > m) {
                count++;
                cur = 0;
            }
            cur += i;
            if (count > D)
                break;
        }
        return count <= D;
    }
};
