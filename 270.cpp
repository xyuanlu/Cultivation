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

// recursibely
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

// using stack
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        stack<TreeNode*> s;
        double epsl = 0.00001;
        double minD = DBL_MAX;
        // s.top is the cloest
        while(root!=nullptr) {
            s.push(root);
            //cout<<root->val<<endl;
            minD = min(minD, abs(root->val - target));
            if (abs(root->val - target) < epsl) {
                break;
            } else if (root->val - target > epsl) {  // root > target
                root = root->left;
            } else {
                root = root->right;
            }
        }
       // cout<<endl<<minD<<endl;
        while(!s.empty()) {
            if (abs(abs(s.top()->val - target) - minD)> epsl) {
                /*cout<<abs(s.top()->val - target)<<" "<<minD<<
                    " "<<abs(abs(s.top()->val - target) - minD)<<endl;
                cout<<"pop"<<s.top()->val<<endl;*/
                s.pop();
            } else {
                break;
            }
        }
        
        return s.top()->val;
    }
};
