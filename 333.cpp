/*
 * 333. Largest BST Subtree
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
    int lres;
    int largestBSTSubtree(TreeNode* root) {
        lres = 0;
        int min, max, size;
        helper(root, min, max, size);
        return lres;
    }
    
    // return if subtree with root r is BST, and its min and max
    bool helper(TreeNode *root, int& min, int& max, int& size) {
        if (root == nullptr) {
            min = INT_MAX;
            max = INT_MIN;
            size = 0;
            return true;
        }
        bool res = false;
        size = 0;
        int lmin, lmax, rmin, rmax, lsize, rsize;
        bool left = helper(root->left, lmin, lmax, lsize);
        bool right = helper(root->right, rmin, rmax, rsize);
        if (left && right && root->val>lmax && root->val<rmin) {
            res = true;
            lres = std::max(lres, 1+lsize+rsize);
            size = 1+lsize+rsize;
        }
        min = std::min(root->val, lmin);
        max = std::max(root->val, rmax);
        return res;
    }
};
