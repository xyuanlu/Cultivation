/*
 * 518. Coin Change 2
 * 
 * You are given coins of different denominations and a total amount of money. Write a
 * function to compute the number of combinations that make up that amount. You may assume
 * that you have infinite number of each kind of coin.
 *
 
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // m[i] means number of ways to get to i
        vector<int> m(amount+1, 0);
        
        m[0]=1;
        for(int j=0; j<coins.size(); ++j) {       // <<<<------------ Having coins or amount on topThis maters a lot.
            for(int i=0; i<=amount; ++i) {        // Coins on top garentee unique ways.
                int n = i+coins[j];  
                if (n<=amount) {
                    m[n] += m[i];
                }
            }
        }
        return m[amount];
    }
};
