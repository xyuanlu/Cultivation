/*
 * 199. Binary Tree Right Side View
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == nullptr)
            return res;
        vector<TreeNode*> t{root};
        vector<TreeNode*> tt;
        
        for(int i=0; i<t.size(); ++i) {
            TreeNode* cur = t[i];
            //cout<<cur->val<<endl;
            if(cur->left != nullptr) {
                tt.push_back(cur->left);
            }
            if(cur->right != nullptr) {
                tt.push_back(cur->right);
            }
            if(i == t.size()-1) {
                res.push_back(cur->val);
                t = tt;
                i=-1;                         // <-----------XXX
                tt = vector<TreeNode*>();
            }
            
        }
        return res;
    }
};
