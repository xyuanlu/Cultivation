/*
* 338. Counting Bits
* Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the
* number of 1's in their binary representation and return them as an array.
*/

class Solution {
public:
    vector<int> countBits(int num) {
        if (num==0)
            return {0};
        // res for number [2^n, 2^(n+1)) is all m[0, 2^) +1
        vector<int> m = {0};
        
        for(int i=0; i<32; ++i) {
            int l=pow(2, i);
            for(int j=0; j<l; ++j) {
                m.push_back(m[j]+1);
                if (l+j==num)
                    return m;
            }
        }
        return m;
    }
};
