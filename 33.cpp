/*
 * 33. Search in Rotated Sorted Array
 */
 
class Solution {
public:
    int search(vector<int>& num, int target) {
        int l=0, r=num.size(), m=0;
        if(num.size()==0) return -1;
        
        while(r-l>1) {
            m = l+(r-l)/2;
            // if left part is sorted
            if(num[l]<num[m]) {
                if(num[l]<=target && num[m] > target) {
                    // target is in sorted part
                    r = m;
                } else {
                    l = m;
                }
            } else { // left is unsorted
                if(num[m] <= target && num[l]>target) {
                    l = m;
                } else {
                    r = m;
                }
                
            }
        }
        return num[l] == target? l: -1;
    }
};
