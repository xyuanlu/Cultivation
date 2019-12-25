/*
 * 156. Binary Tree Upside Down
 *
 * Given a binary tree where all the right nodes are either leaf nodes with a sibling
 * (a left node that shares the same parent node) or empty, flip it upside down and turn it
 * into a tree where the original right nodes turned into left leaf nodes. Return the new root.
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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        vector<TreeNode*> v = helper(root);
        return v[0];
    }
    
    //return a new root and its right most child
    vector<TreeNode*> helper(TreeNode* root) {
        if (root == nullptr)
            return {nullptr, nullptr};
        if (root->left == nullptr) {
            TreeNode *n = new TreeNode(root->val);
            return {n, n};
        }
            
        
        TreeNode *newRight = new TreeNode(root->val);
        TreeNode *newLeft = root->right == nullptr? nullptr : new TreeNode(root->right->val);
        vector<TreeNode*> v =  helper(root->left);
        v[1]->left = newLeft;
        v[1]->right = newRight;
        return {v[0], newRight};
    }
};
