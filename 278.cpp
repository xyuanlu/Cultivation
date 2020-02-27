/*
 * 278. First Bad Version
 */
 
 // Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long l=0, r=n, mid;
        r++;
        while(r-l>1) {
            mid = l + (r-l)/2;
            if (isBadVersion(mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return l+1;
    }
};
