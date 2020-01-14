/*
 * 1302. Deepest Leaves Sum
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
    int deepestLeavesSum(TreeNode* root) {
        int res = 0;
        if (root == nullptr)
            return 0;
        queue<TreeNode*> q, qq;
        q.push(root);
        while (!q.empty()) {
            TreeNode* t = q.front();
            //cout<<t->val<<" ";
            res += t->val;
            q.pop();
            if (t->left != nullptr) {
                qq.push(t->left);
            }
            if (t->right != nullptr) {
                qq.push(t->right);
            }
            if (q.empty()) {
                if (!qq.empty()) {
                    q = qq;
                    qq = queue<TreeNode*>();
                    res = 0;
                }
            }
        }
        
        return res;
    }
};
