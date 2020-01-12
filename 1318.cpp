/*
 * 1318. Minimum Flips to Make a OR b Equal to c
 * 
 * Given 3 positives numbers a, b and c. Return the minimum flips required in some
 * bits of a and b to make ( a OR b == c ). (bitwise OR operation).
 * Flip operation consists of change any single bit 1 to 0 or change the bit 0 to 1 in their binary representation.
 */
 
 class Solution {
public:
    int minFlips(int a, int b, int c) {
        unsigned n=1;
        int res = 0;
        for(int i=0; i<32; ++i) {
            if (n>a && n>b && n>c)
                break;
            //cout<<n<<": "<<((a&n) | (b&n))<<(c&n)<<endl;
            if ( ((a&n) | (b&n)) == (c&n)) {
                n = n<<1;
                continue;
            }
            // if the bit at c is 0, then the bit at a and b should be 0
            if ((c&n) == 0) {
                if ((a&n)!=0) {
                    //cout<<n<<endl;
                    res++;
                }
                if ((b&n)!=0) {
                    //cout<<n<<endl;
                    res++;
                }   
            } else {   // the bit at c is 1
                //cout<<n<<endl;
                res = res+1;
            }
            n = n<<1;
        }
        
        return res;
    }
};
