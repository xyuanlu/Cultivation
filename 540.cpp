/*
 * 540. Single Element in a Sorted Array
 *
 * You are given a sorted array consisting of only integers where every element appears exactly
 * twice, except for one element which appears exactly once. Find this single element that appears only once.
 */
 
class Solution {
public:
    int singleNonDuplicate(vector<int>& n) {
        /*int res = 0;
        for(int i:nums) {
            res = res^i;
        }
        return res;*/
        
        // Before and after the single element, 
        // idx will be different for non single elem. 
        // (it is the same as the preor or after elem for idx%2==1 or 0).
        // Find the first F in T T F F
        int l=-1, r=n.size()-1, m;
        while(r-l>1) {
            m = (l+r)/2;
            //cout<<l<<" "<<r<<" "<<m<<endl;
            if((m%2==0 && n[m] == n[m+1]) || 
               (m%2==1 && n[m] == n[m-1]) ) {
                l = m;
            }
            else {
                r = m;
            }
        }
        return n[l+1];
        
    }
};
