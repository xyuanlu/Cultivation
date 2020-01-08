/*
 * 339. Nested List Weight Sum
 */
 class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        return helper(nestedList, 1);
    }
    
    int helper(const vector<NestedInteger>& nestedList, int depth) {
        int res = 0;
        for(auto it:nestedList) {
            if (it.isInteger()) {
                res+=it.getInteger()*depth;
            } else {
                res += helper(it.getList(), depth+1);
            }
        } 
        return res;
    }
};
