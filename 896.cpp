/*
 * 896. Monotonic Array
 *
 * An array is monotonic if it is either monotone increasing or monotone decreasing.
 * An array A is monotone increasing if for all i <= j, A[i] <= A[j].  An array A is
 * monotone decreasing if for all i <= j, A[i] >= A[j].
 * Return true if and only if the given array A is monotonic.
 *
 */
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int i=0; 
        // monotone decreasing
        for(; i<A.size()-1; ++i) {
            if (A[i]<A[i+1])
                break;
        }
        if(i == A.size()-1)
            return true;
        
        // monotone increasing
        i = 0;
        for(; i<A.size()-1; ++i) {
            if (A[i]>A[i+1])
                break;
        }
        if(i == A.size()-1)
            return true;
        return false;
    }
};
