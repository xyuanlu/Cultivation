/*
 * 1317. Convert Integer to the Sum of Two No-Zero Integers
 */
 
 class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> res;
        for(int i=1; i<=n/2; ++i) {
            if (valid(i) && valid(n-i)) {
                res = {i, n-i};
                return res;
            }
        }
        return res;
        
    }
    
    bool valid(int n) {
        while(n>0) {
            if(n%10 ==0) return false;
            n = n/10;
        }
        return true;
    }
};
