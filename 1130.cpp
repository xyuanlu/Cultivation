/*
 * 1130. Minimum Cost Tree From Leaf Values
 */
 
 class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        // m[i][j] is the result for [i, j)
        vector<vector<int>> m(arr.size(), vector<int>(arr.size()+1, INT_MAX));
        for(int i=arr.size()-1; i>=0; --i) {
            for(int j=i+1; j<=arr.size(); ++j) {
                if (j==i+1) {
                    //cout<<i<<" "<<arr[i]<<endl;
                    m[i][j] = arr[i];
                } else if (j==i+2) {
                    m[i][j] = arr[i] * arr[i+1];
                    
                }else {
                    //int temp = INT+MAX;
                    for(int k=i+1; k<j; ++k) {
                        int left = k>i+1 ? m[i][k] : 0;
                        int right = j>k+1? m[k][j] : 0;
                        m[i][j] = min(m[i][j],
                                      left+right+findMax(arr, i, k)*findMax(arr, k, j));
                    }
                }
                //cout<<i<<" "<<j<<" "<<m[i][j]<<endl;
            }
        }
        return m[0][arr.size()];
        
    }
    
    // find max in [i, j)
    int findMax(vector<int>& arr, int i, int j) {
        int res = arr[i];
        for(int id = i; id<j; ++id) {
            res = max(res, arr[id]);
        }
        return res;
    }
};
