/*
 * 1026. Maximum Difference Between Node and Ancestor
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
    int maxAncestorDiff(TreeNode* root) {
        _res = 0;
        helper(root);
        return _res;
    }
    
    // return max [0] and min [1] of the subtree root
    // return an empty vector if root is nullptr
    vector<int> helper(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        vector<int> resl, resr;
        int maxx = root->val, minn = root->val;
        if (root->left != nullptr) {
            resl = helper(root->left);
            maxx = max(maxx, resl[0]);
            minn = min(minn, resl[1]);
        }
        if (root->right != nullptr) {
            resr = helper(root->right);
            maxx = max(maxx, resr[0]);
            minn = min(minn, resr[1]);
        }
        _res = max(_res, max(abs(root->val - maxx), abs(root->val - minn)));
        res = {maxx, minn};
        return res;
    }
private:
    int _res;
};
