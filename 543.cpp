/*
 * 543. Diameter of Binary Tree
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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int len = 0;
        return helper(root, len);
    }
    int helper(TreeNode* root, int& len) {
        if(root == nullptr) {
            len = 0;
            return 0;
        }
        int res = 0;
        int len1=0, len2=0;
        res = max(res, helper(root->left, len1));
        res = max(res, helper(root->right, len2));
        len = max(len1, len2)+1;
        res = max(res, len1+len2);
        //cout<<root->val<<" "<<len1<<" "<<len2<<" "<<res<<endl;
        return res;
    }
};
