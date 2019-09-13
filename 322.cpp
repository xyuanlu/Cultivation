/*
 * 322. Coin Change
 * You are given coins of different denominations and a total amount of money amount.
 * Write a function to compute the fewest number of coins that you need to make up that amount.
 * If that amount of money cannot be made up by any combination of the coins, return -1.
 */
 
 
 class Solution {
public:
    int coinChange(vector<int>& coins, int target) {
        vector<int> memo(target+1, target+1);
        memo[0] = 0;
        sort(coins.begin(), coins.end());
        for(int i=0; i<=target; ++i) {
            for(int j=0; j<coins.size(); ++j) {
                int temp = i-coins[j];
                if(temp <0) break;
                memo[i] = min(memo[i], 1+memo[temp]);
            }
            //cout<<memo[i]<<endl;
        }
        return memo[target] == target+1? -1:memo[target];
    }
};
