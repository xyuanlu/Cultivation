/*
 * 1008. Construct Binary Search Tree from Preorder Traversal
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
    // Find the first element larger than current
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder, 0, preorder.size());
    }
    
    TreeNode* helper(vector<int>& n, int l, int r) {
        if(r==l)
            return nullptr;
        //cout<<l<<" "<<r<<endl;
        TreeNode *t = new TreeNode(n[l]);
        if(r == l+1) {
            return t;
        }
        int i = l+1;
        for(; i<r; ++i) {
            if(n[i] > n[l]){
                break;
            }
        }
        t->left = helper(n, l+1, i);
        t->right = helper(n, i, r);
        return t;
    }
};
