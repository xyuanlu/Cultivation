/*
 * 298. Binary Tree Longest Consecutive Sequence
 * Given a binary tree, find the length of the longest consecutive sequence path.
 * 
 * The path refers to any sequence of nodes from some starting node to any node in the
 * tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).
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
    int longestConsecutive(TreeNode* root) {
        int maxRes = 0;
        helper(root, maxRes);
        
        return maxRes;  
    }
    
    // return the max len, headed by root
    int helper(TreeNode* root, int& maxRes) {
       if (root==nullptr)
           return 0;
        
        int left = helper(root->left, maxRes);
        int right = helper(root->right, maxRes);
        
        //cout<<root->val<<" "<<left<<" "<<right<<endl;
        
        int res = 1;
        if (left!=0 && root->left->val == root->val+1) {
            res = max(res, 1+left);    
        }
        
        if (right!=0 && root->right->val == root->val+1) {
            res = max(res, 1+right);    
        }
        
        maxRes = max(maxRes, max(res, max(right, left)));
        //cout<<maxRes<<endl;
        
        return res;
    }
};
