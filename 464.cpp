/*
 * 464. Can I Win
 * The player who first causes the running total to reach or exceed desiredTotal wins.
 * Given an integer maxChoosableInteger and another integer desiredTotal,
 * determine if the first player to move can force a win, assuming both players play optimally.
 *
 * You can always assume that maxChoosableInteger will not be larger than 20 and desiredTotal will not be larger than 300.
 */
 
class Solution {
public:
    unordered_map<int, bool> m;
    int l;
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal==0)
            return true;
        int sum = (maxChoosableInteger+1)* maxChoosableInteger/2;
        l = maxChoosableInteger;
        if (sum < desiredTotal)
            return false;
        
        return helper(0, desiredTotal);
    }
    
    // the player will choose an int from set. If tar<=num, the player wins and return true
    bool helper(int s, int target) {
        if (target<=0)
            return false;
        /*if (m.find(s)!=m.end())
                return m[s]; */
        for (int i=0; i<l; ++i) {
            if (!(s & (1<<i))) {
                int t = s | (1<<i);
                if (m.find(t)!=m.end())
                    return m[t];
                //cout<<i<<endl;
                if (!helper(t, target-i-1)) {
                    m[t] = true;
                    return true;
                }
            }
        }
        m[s] = false;
        return false;
    }
};
