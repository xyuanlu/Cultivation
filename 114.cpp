/*
 * 114. Flatten Binary Tree to Linked List
 * 
 * Given a binary tree, flatten it to a linked list in-place.
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
    void flatten(TreeNode* root) {
        if (root == nullptr)
            return;
        TreeNode *right = root->right;
        flatten(right);
        
        TreeNode *left = root->left;
        flatten(left);
        
        if(root->left != nullptr) {
            root->left = nullptr;
            root->right = left;
            TreeNode *cur=left;
            while(cur->right!=nullptr) {     // <-----------
                cur = cur->right;
            }
            cur->right = right;
        }
    }
};
