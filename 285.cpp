/*
* 285. Inorder Successor in BST
*   Given a binary search tree and a node in it, find the in-order successor of that node in the BST.
*
*   The successor of a node p is the node with the smallest key greater than p.val.
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        //case 1.
        // if p->right != nullptr, return the first node has no left child.
        TreeNode *res = nullptr;
        if(p->right != nullptr) {
            p = p->right;
            res = p;
            while(p->left != nullptr) {
                p = p->left;
                res = p;
            }
            return res;
        }
        
        // case 2.
        stack<TreeNode*> s;
        while (!s.empty() || root!=nullptr) {
            //cout<<root->val<<endl;
            if(root->val == p->val) {
                return  s.empty()? nullptr:s.top();
            }
            if(root->val < p->val) {
                root = root->right;
            } else {
                s.push(root);
                root=root->left;
            }
        }
        //cout<<"dd"<<endl;
        return s.empty()? nullptr:s.top();
        
    }
};
