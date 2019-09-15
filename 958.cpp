/*
 * 958. Check Completeness of a Binary Tree
 * 
 * Given a binary tree, determine if it is a complete binary tree.
 *
 * Definition of a complete binary tree from Wikipedia:
 * In a complete binary tree every level, except possibly the last,
 * is completely filled, and all nodes in the last level are as far
 * left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
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
    bool isCompleteTree(TreeNode* root) {
        int level = 0, s = 1;
        bool hasHole = false;
        queue<TreeNode*> q, qq;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if(cur->left == nullptr) {
                hasHole = true;
            } else {
                if (hasHole)
                    return false;
                qq.push(cur->left);
            } 
            if(cur->right == nullptr) {
                hasHole = true;
            } else {
                if (hasHole)
                    return false;
                qq.push(cur->right);
            }
            
            if(q.empty()) {
                if(!qq.empty()) {
                    if(s!=pow(2, level)) {
                        return false;
                    }                    
                }
                level++;
                q = qq;
                s = qq.size();
                qq = queue<TreeNode*>();
            }
        }
        return true;
    }
};
