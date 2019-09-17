/*
 * 43. Multiply Strings
 * Given two non-negative integers num1 and num2 represented as strings,
 * return the product of num1 and num2, also represented as a string.
 */
 
 class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> res(num1.size()+num2.size(), 0);
        for(int i=num1.size()-1; i>=0; --i) {
            for(int j=num2.size()-1; j>=0; --j) {
                int t = (num1[i]-'0') * (num2[j]-'0');
                //cout<<i<<" "<<j<<" "<<t<<endl;
                res[i+j+1] += t%10;
                t = t/10 + res[i+j+1]/10;
                res[i+j+1] = res[i+j+1]%10;
                int curIdx = i+j;
                while(t>0) {
                    res[curIdx] += t;
                    t = res[curIdx]/10;
                    res[curIdx] = res[curIdx]%10;
                    curIdx--;
                }
                
                
            }
        }
        /*for(auto in:res) {
            cout<<in<<" ";
        }
        */
        string result;
        int i=0;
        while(i<res.size() && res[i]==0 )
            ++i;
        while(i<res.size()) {
            result += ('0'+res[i]);
            ++i;
        }
        return result.size()==0? "0": result;
    }
};
