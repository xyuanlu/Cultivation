/*
 * 364. Nested List Weight Sum II
 *  Given a nested list of integers, return the sum of all integers
 * in the list weighted by their depth.
 * Each element is either an integer, or a list -- whose elements may also be integers or other lists.
 *
 * Different from the previous question where weight is increasing from root to leaf, now
 * the weight is defined from bottom up. i.e., the leaf level integers have weight 1, and the root
 * level integers have the largest weight.
 */
 
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        // depth -> sum of each level
        vector<int> m;
        helper(nestedList, 0, m);
        
        int depth = m.size();
        int res = 0;
        for(int i=0; i<m.size(); ++i) {
            res += m[i] * (depth-i);
        }
        return res;
    }
    
    void helper(vector<NestedInteger>& nestedList, int d, vector<int>& m ) {
        if (d>=m.size()) {
            m.resize(d+1);
        }
        
        for(int i=0; i<nestedList.size(); ++i) {
            if (nestedList[i].isInteger()) {
                m[d] += nestedList[i].getInteger();
            } else {
                helper(nestedList[i].getList(), d+1, m);
            }
        }
        
    }
    
};




class Solution2 {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int maxDepth = getMaxDepth(nestedList, 1);
        return helper(nestedList, maxDepth);
    }
    
    int getMaxDepth(const vector<NestedInteger>& nestedList, int depth) {
        int res = 1;
        for (const auto& it : nestedList) {
            if (!it.isInteger()) {
                res = max(res, getMaxDepth(it.getList(), depth)+1);
            }
        }
        return res;
    }
    
    int helper(const vector<NestedInteger>& nestedList, int depth) {
        int res = 0;
        for(auto& it:nestedList) {
            if (it.isInteger()) {
                res+=it.getInteger()*depth;
            } else {
                res += helper(it.getList(), depth-1);
            }
        } 
        return res;
    }
    
};


class Solution2 {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        // idea bowwored from BFS
        vector<NestedInteger> next;
        int visited = 0, cur = 0;
        while(!nestedList.empty()) {
            //cur += visited;
            for (int i=0; i<nestedList.size(); ++i){
                if (nestedList[i].isInteger()) {
                    cur+=nestedList[i].getInteger();
                } else {
                    next.insert(next.end(),
                                nestedList[i].getList().begin(), nestedList[i].getList().end());
                }
            }
            //cout<<cur<<endl;
            nestedList = next;
            next.clear();
            visited += cur;
        }
        return visited;
    }
};



