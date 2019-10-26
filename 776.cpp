/*
 * 776. Split BST
 * 
 * Given a Binary Search Tree (BST) with root node root, and a target value V,
 * split the tree into two subtrees where one subtree has nodes that are all
 * smaller or equal to the target value, while the other subtree has all nodes
 * that are greater than the target value.  It's not necessarily the case that
 * the tree contains a node with value V.
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
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        /*
         * Initiallt, A tree will be split in to two parts into 
         * {root->left, root} amd {root->right}, or the other way around.
         * one part contains root and the other part will also be split
         * into two parts follow the same rule.
         */
        vector<TreeNode*> res(2, nullptr);
        if (root->val<=V) {
            vector<TreeNode*> t = splitBST(root->right, V);
            root->right = t[0];
            res[0] = root;
            res[1] = t[1];
        } else {
            vector<TreeNode*> t = splitBST(root->left, V);
            root->left = t[1];
            res[1] = root;
            res[0] = t[0];
        }
        return res;
                                                        
};
