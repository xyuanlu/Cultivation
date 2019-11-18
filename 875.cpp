/*
 * 875. Koko Eating Bananas
 * Koko loves to eat bananas.  There are N piles of bananas, the i-th pile has piles[i] bananas. 
 * The guards have gone and will come back in H hours.
 *
 * Koko can decide her bananas-per-hour eating speed of K.  Each hour, she chooses some pile of bananas,
 * and eats K bananas from that pile.  If the pile has less than K bananas, she eats all of them instead,
 * and won't eat any more bananas during this hour.
 *
 * Koko likes to eat slowly, but still wants to finish eating all the bananas before the guards come back.
 * 
 * Return the minimum integer K such that she can eat all the bananas within H hours.
 */
 
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        if (piles.size()==0)
            return 0;
        // BS
        int l = piles[0], r = piles[0], m;
        for(int i=0; i<piles.size(); ++i) {
            l = min(l, piles[i]);
            r = max(r, piles[i]);
        }
        l = min(1, l/H);
        if (l!=0)
            l--;
        //cout<<l<<" "<<r<<endl;
        // F F T T
        while(r>l+1) {
            m = l + (r-l)/2;
            //cout<<l<<" "<<r<<" "<<m<<endl;
            if (helper(piles, H, m)) {
                //cout<<m<<endl;
                r = m;
            } else {
                l = m;
            }
        }
        return r;
    }
    
    bool helper(vector<int>& piles, int H, int m) {
        for(int i=0; i<piles.size(); ++i) {
            if (H<=0)
                return false;
            H -= piles[i]/m;
            if (piles[i]%m!=0)
                H--;
        }
        return H>=0;
        
    }
};
