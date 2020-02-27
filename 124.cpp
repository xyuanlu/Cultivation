/*
 * 124. Binary Tree Maximum Path Sum
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
    int maxPathSum(TreeNode* root) {
        vector<int> t = helper(root);
        return t[0];
    }
    
    // max path in this subtree, max sum including the root
    vector<int> helper(TreeNode *root) {
        vector<int> res;
        if (root == nullptr)
            return res;
        res = {0, 0};
        vector<int> l = helper(root->left);
        vector<int> r = helper(root->right);
        if(l.size()==0 && r.size()==0)
            return {root->val, root->val};
        if (l.size()==0) return {max(max(0, r[1])+root->val, r[0]), max(root->val, r[1]+root->val)};
        if (r.size()==0) return {max(max(0, l[1])+root->val, l[0]), max(root->val, l[1]+root->val)};
        
        res[1] = max(0, max(l[1], r[1])) + root->val;
        res[0] = max(l[1]+r[1]+root->val, max(l[0], r[0]));
        res[0] = max(res[0], res[1]);
        return res;
    }
};

class Solution2 {
public:
    // pair(max including root, max not including root)
    pair<int, int> helper(TreeNode* root) {
        if (!root) {
            return make_pair(-1000000, -10000000);
        }
        else {
            auto l_pair = helper(root->left);
            auto r_pair = helper(root->right);
            int new_max_with_root = max(root->val,
                                      max(root->val + l_pair.first,
                                        root->val + r_pair.first));
            int new_max_without_root = max(max(l_pair.second, r_pair.second),
                                           max(l_pair.first,
                                               max(r_pair.first, root->val + l_pair.first + r_pair.first)));
            return make_pair(new_max_with_root, new_max_without_root);
        }
    }
    int maxPathSum(TreeNode* root) {
        auto res = helper(root);
        return max(res.first, res.second);
    }
};
