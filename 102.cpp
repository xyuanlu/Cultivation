/*
 * 102. Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root==nullptr)
            return res;
        queue<TreeNode*> q, qq;
        vector<int> r;
        q.push(root);
        while(!q.empty()) {
            TreeNode *t = q.front();
            r.push_back(t->val);
            if(t->left!=nullptr) qq.push(t->left);
            if(t->right!=nullptr) qq.push(t->right);
            q.pop();
            if (q.empty()) {
                q = qq;
                res.push_back(r);
                r.clear();
                qq=queue<TreeNode*>();
            }
        }
        
        return res;
    }
};
