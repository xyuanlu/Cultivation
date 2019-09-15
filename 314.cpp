/*
 * 314. Binary Tree Vertical Order Traversal
 * Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).
 * 
 * If two nodes are in the same row and column, the order should be from left to right.
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> memo;
        vector<vector<int>> res;
        
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            if (t.first == nullptr)
                continue;
            memo[t.second].push_back(t.first->val);
            q.push(make_pair(t.first->left, t.second-1));
            q.push(make_pair(t.first->right, t.second+1));
            
        }
        
        for(const auto& it:memo) {
            res.push_back(it.second);
        }
        return res;
    }
};
