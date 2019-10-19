/*
 * 250. Count Univalue Subtrees
 * Given a binary tree, count the number of uni-value subtrees.
 *
 * A Uni-value subtree means all nodes of the subtree have the same value.
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
    int countUnivalSubtrees(TreeNode* root) {
        
        int res = 0;
        
        helper(root, res);
        
        return res;
        
        
    }
    
    // return true if true is a uni-value tree
    bool helper(TreeNode * root, int& res) {
        if (root == nullptr) {
            return true;
        }
        //int res = 0;
        bool left =  helper(root->left, res);
        bool right  = helper(root->right, res);
        
        if ((left && (root->left ==nullptr || root->val == root->left->val))
            && (right && (root->right == nullptr || root->val == root->right->val))) {
            res +=1;
            return true;
        }
        
        return false;
        
    }
};
