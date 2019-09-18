/*
50. Pow(x, n)

Implement pow(x, n), which calculates x raised to the power n (xn).

*/

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N<0) {
            x = 1/x;
            N =-N;
        }
        return helper(x, N);
    }
    
    double helper(double x, int N) {
        //cout<<N<<endl;
        if (N==0)
            return 1.0;
        double h = helper(x, N/2);
        if (N%2 == 0) {
            return h*h;
        } else {
            return h*h*x;
        }
    }     
};
