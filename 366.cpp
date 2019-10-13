/*
* 366. Find Leaves of Binary Tree
* Given a binary tree, collect a tree's nodes as if you were doing this:
* Collect and remove all leaves, repeat until the tree is empty.
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
    vector<vector<int>> findLeaves(TreeNode* root) {
        // distance from node -> node value
        map<int, vector<int>> m;
        
        helper(root, m);
        
        vector<vector<int>> res;
        for (auto i:m) {
            res.push_back(i.second);
        }
        return res;
    }
    
    int helper(TreeNode* root, map<int, vector<int>>& m) {
        if (root==nullptr) {
            return -1;
        }
        int d = max(helper(root->left, m), helper(root->right, m));
        m[d].push_back(root->val);
        return d+1;
    }
};
