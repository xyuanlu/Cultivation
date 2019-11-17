/*
 * 740. Delete and Earn
 * Given an array nums of integers, you can perform operations on the array.
 * 
 * In each operation, you pick any nums[i] and delete it to earn nums[i] points. After,
 * you must delete every element equal to nums[i] - 1 or nums[i] + 1.
 *
 * You start with 0 points. Return the maximum number of points you can earn by applying such operations.
 */
 
class Solution {
public:
    /*
     * hint: If you take a number, you might as well take them all.
     */
    class P{
    public:
        int v;
        int c;
        
    };
    
    int deleteAndEarn(vector<int>& nums) {
        if (nums.size()==0)
            return 0;
        map<int, int> freq;
        for(int i=0; i<nums.size(); ++i) {
            freq[nums[i]] ++;
        }
        vector<P> f;
        for(auto &it:freq) {
            f.push_back({it.first, it.second});
            //cout<<it.first<<" "<<it.second<<endl;
        }
        
        // m[i][0] do not use number at f[i]
        vector<vector<int>> m(f.size(), vector<int>(2, 0));
        m[0][0] = 0;
        m[0][1] = f[0].v * f[0].c;
        
        for(int i=1; i<m.size(); ++i) {
            //cout<<i<<endl;
            //cout<<m[i-1][0]<<" "<<m[i-1][1]<<endl;
            m[i][0] = max(m[i-1][0], m[i-1][1]);
            if (f[i].v == f[i-1].v+1) {
                m[i][1] = m[i-1][0] + f[i].v * f[i].c;
            } else {
                m[i][1] = max(m[i-1][0], m[i-1][1]) + f[i].v * f[i].c;
            }
        }
        //cout<<f.size()-1<<endl;
        return max(m[f.size()-1][0], m[f.size()-1][1]);
    }
};
