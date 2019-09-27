/*
 * 129. Sum Root to Leaf Numbers
 *  Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
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
    int sumNumbers(TreeNode* root) {
        int res = 0;
        string temp;
        
        helper(res, temp, root);
        return res;
    }
    
    void helper(int& res, string temp, TreeNode* root) {
            if(root == nullptr) {
                return;
            }
            temp += to_string(root->val);
            if(root->left == nullptr && root->right == nullptr) {
                res += stoi(temp);
                return;
            }
            helper(res, temp, root->left);
            helper(res, temp, root->right);
        }
};
