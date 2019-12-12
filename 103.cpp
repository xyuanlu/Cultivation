/*
 * 103. Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root==nullptr)
            return res;
        queue<TreeNode*> q, qq;
        vector<int> cur;
        q.push(root);
        bool r = false;
        while(!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            cur.push_back(t->val);
            if (t->left!=nullptr) {
                qq.push(t->left);
            }
            if (t->right!=nullptr) {
                qq.push(t->right);
            }
            if (q.empty()) {
                q = qq;
                qq = queue<TreeNode*> ();
                if (r) {
                    reverse(cur.begin(), cur.end());
                }
                res.push_back(cur);
                r = !r;
                cur.clear();
            }
        }
        return res;
        
    }
};
