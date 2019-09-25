/*
 * 189. Rotate Array
 * Given an array, rotate the array to the right by k steps, where k is non-negative.
 */
 
class Solution {
public:
    void rotate(vector<int>& n, int k) {
        k = k%n.size();
        vector<int> m(k);
        for(int i=0; i<k; ++i) {
            m[i] = n[n.size()-k+i];
            //cout<<m[i]<<" ";
            
        }
        for(int i=n.size()-1; i>=0; --i) {
            if(i-k<0) {
                n[i] = m[i];
            } else {
                n[i] = n[i-k];
            }
        }
    }
};
