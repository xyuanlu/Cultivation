/*
 * 257. Binary Tree Paths
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * Note: A leaf is a node with no children.
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string temp;
        helper(res, temp, root);
        return res;
    }
    
    
    // push to res when meet leaf node. Not just nullptr
    void helper(vector<string>& res, string temp, TreeNode* root) {
        if(root == nullptr) {
            return;
        }
        
        //cout<<temp<<endl;
        if(root->left == nullptr && root->right == nullptr) {
            temp += to_string(root->val);          // <--- seperate for leaf or null leaf
            res.push_back(temp);
            return;
        }
        
        temp += to_string(root->val) +"->";
        if(root->left != nullptr)
            helper(res, temp, root->left);
        if(root->right != nullptr)
        helper(res, temp, root->right);
    }
};
