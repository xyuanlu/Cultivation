/*
 * 105. Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int left = 0, right = inorder.size();
        return helper(preorder, inorder, left, right, 0);
    }
    
    // left and right are bountry for inOrder vector. [left, right)
    // for preOrder vector, the interval is bounded by the [idx, idx+Len)
    TreeNode* helper(const vector<int>& preorder, const vector<int>& inorder,
                     int left, int right, int idx) {
        if(left == right) {
            return nullptr;
        }
        // create node of 'idx' in preOrder array
        TreeNode *t = new TreeNode(preorder[idx]);
        // find the root (t) idx in inorder array
        auto it = find(inorder.begin(), inorder.end(), preorder[idx]);
        int i = std::distance(inorder.begin(), it);
        
        //create left child
        t->left = helper(preorder, inorder, left, i, idx+1);
        // compute len of left child in the inorder array, so that we know the 
        // idx of the root if right child in preorder array
        int leftTreeLen = i-left;
        t->right = helper(preorder, inorder, i+1, right, idx+leftTreeLen+1);
        return t;
        
    }
};
