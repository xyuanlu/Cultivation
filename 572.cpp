/*
* 572. Subtree of Another Tree
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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return helper(s, t, false) || helper(s, t, true);
    }
    
    // of sl = true, can be sloppyly same
    bool helper(TreeNode* s, TreeNode* t, bool sl){
        if (s == nullptr && t == nullptr)
            return true;
        if (s == nullptr) return false;
        if (t ==nullptr ) 
            return sl;
        
        if (s->val == t->val) {
            bool res = (helper(s->left, t->left, false) &&
                         helper(s->right, t->right, false));
            if (!sl)
                return res;
            if (res)
                return true;
        }
        
        if(!sl) return false;
        return (helper(s->left, t, true) || helper(s->right, t, true));
        
    }
};
