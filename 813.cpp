/*
 * 813. Largest Sum of Averages
 * We partition a row of numbers A into at most K adjacent (non-empty) groups,
 * then our score is the sum of the average of each group. What is the largest score we can achieve?
 * 
 * Note that our partition must use every number in A, and that scores are not necessarily integers.
 * 1 <= A.length <= 100.
 * 1 <= A[i] <= 10000.
 * 1 <= K <= A.length.
 * Answers within 10^-6 of the correct answer will be accepted as correct.
 */
 
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        vector<int> sum{0};
        int s = 0;
        double res = 0;
        for(int i=0; i<A.size(); ++i) {
            s+=A[i];
            sum.push_back(s);
            //cout<<s<< ' ';
        }
        //cout<<endl;
        
        
        // m[i][k] use prev i (include) elem devide k groups
        vector<vector<double>> m(A.size(), vector<double>(K+1, -10000000));
        for (int i=0; i<A.size(); ++i) {
            for (int k=1; k<=K; ++k) {
                m[i][1] = (double)sum[i+1]/(i+1);
                for(int j=max(0, k-2); j<i; ++j) {
                    m[i][k] = max(m[i][k], m[j][k-1]+(double)(sum[i+1]-sum[j+1])/(i-j));
                }
                //cout<<m[i][k]<<" ";
                if(i==A.size()-1) {
                    res = max(res, m[i][k]);
                }
            }
            //cout<<endl;
        }
                                  
        return res;
    }
};
