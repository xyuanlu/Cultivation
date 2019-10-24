/*
 * 465. Optimal Account Balancing
 */
 
 
 class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        // Count a person's total +/- number
        // every time apply the person with max + number to person with min - number
        unordered_map<int, int> debts;
        for(int i=0; i<transactions.size(); ++i) {
            debts[transactions[i][0]] -= transactions[i][2];
            debts[transactions[i][1]] += transactions[i][2];
        }
        
        vector<int> acc;
        for(auto& it:debts) {
            if(it.second!=0) {
                acc.push_back(it.second);
            }
        }
        int res=1000000;
        helper(acc, 0, 0, res);
        return res;
    }
    
    void helper(vector<int>& acc, int idx, int cur, int& res) {
        //cout<<idx<<" "<< acc.size()<<endl;
        
        if (cur>res) {
            return;
        }
        
        while(idx<acc.size() && acc[idx]==0) ++idx;
        
        if (idx == acc.size()) {
            ///cout<<cur<<endl;
            res = min(res, cur);
            return;
        }
        
        //int temp = INT_MAX;
        for(int i=idx+1; i<acc.size(); ++i) {
            if (acc[i] * acc[idx] <0) {
                //cout<<acc[i]<<" "<<acc[idx]<<endl;
                acc[i] += acc[idx];
                helper(acc, idx+1, cur+1, res);
                acc[i] -= acc[idx];
            }
        }
        return; // temp;
    }
};
