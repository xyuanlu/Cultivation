/*
 *270. Closest Binary Search Tree Value
 *
 * Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.
 * Given target value is a floating point.
 * You are guaranteed to have only one unique value in the BST that is closest to the target.
 *
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
    int closestValue(TreeNode* root, double target) {
        float e = 0.000001;
       // cout<<"xxx "<<abs(root->val - target)<<endl;
        if (abs(root->val - target) < e) { // t == val
            return root->val;
        }
        if (root->right != nullptr && root->val < target) { //  val < t
            int t = closestValue(root->right, target);
            return abs(root->val - target) > abs(t-target) ?
                                t: root->val;
        }
        else if (root->left != nullptr){
            int t = closestValue(root->left, target);
           // cout<<abs(root->val - target)<<" "<<abs(t-target)<<endl;
            return abs(root->val - target) > abs(t-target) ?
                                t: root->val;
        }
        return root->val;
    }
};
