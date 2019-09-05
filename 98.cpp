/*
 * Given a binary tree, determine if it is a valid binary search tree (BST).
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
    bool isValidBST(TreeNode* root) {
        return helper(root, -2147483649, 2147483648);
    }
    
    // the max value of the tree should < hb, min value should > lb
    bool helper(TreeNode* root, long long lb, long long hb) {
        if (root == nullptr) {
            return true;
        }
        if (root->val <= lb || root->val >= hb){
            //cout<<lb<<" "<<hb<<endl;
            return false;
        }
        return helper(root->left, lb, root->val) && helper(root->right, root->val, hb);
        
    }
};
