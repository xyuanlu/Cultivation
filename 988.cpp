/*
 * 988. Smallest String Starting From Leaf
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
    string smallestFromLeaf(TreeNode* root) {
        string res;
        //int minSize = INT_MAX;
        string temp;
        
        helper(root, res, temp);
        return res;
    }
    
    void helper(TreeNode* root, string& res, string& temp) {
        if (root == nullptr ) {
            return;
        } 
        temp+= ('a'+ root->val);
        if(root->left == nullptr && root->right == nullptr) {
            string cand = temp;
            reverse(cand.begin(), cand.end());
            if (res.empty() || cand < res ) {
                //minSize = cand.size();
                res = cand;
            }
            temp.pop_back();             //<<<------- BT, also pop here
            return;
        }
        helper(root->left, res,  temp);
        helper(root->right, res,  temp);
        temp.pop_back();
    }
};








