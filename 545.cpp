/*
 * 545. Boundary of Binary Tree
 * Given a binary tree, return the values of its boundary in anti-clockwise direction starting
 * from root. Boundary includes left boundary, leaves, and right boundary in order without duplicate
 * nodes.  (The values of the nodes may still be duplicates.)
 *
 * Left boundary is defined as the path from root to the left-most node. Right boundary is defined
 * as the path from root to the right-most node. If the root doesn't have left subtree or right
 * subtree, then the root itself is left boundary or right boundary. Note this definition only
 * applies to the input binary tree, and not applies to any subtrees.
 *
 * The left-most node is defined as a leaf node you could reach when you always firstly travel
 * to the left subtree if exists. If not, travel to the right subtree. Repeat until you reach a leaf node.
 *
 * The right-most node is also defined by the same way with left and right exchanged.
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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
            return vector<int> ();
        
        TreeNode *ll, *rr;
        
        // left 
        vector<int> left;
        TreeNode *l = root->left;
        while(l!= nullptr) {
            ll = l;
            left.push_back(l->val);
            if (l->left != nullptr) {
                l = l->left;
            } else {
                l = l->right;
            }
        }
        
        // right
        vector<int> right;
        TreeNode *r = root->right;
        while(r!= nullptr) {
            rr=r;
            right.push_back(r->val);
            if (r->right != nullptr) {
                r = r->right;
            } else {
                r = r->left;
            }
        }
        
        
        /*for(auto i:left) {
            cout<<i<<" ";
        }
        cout<<endl;
        
        cout<<"r"<<endl;
        for(auto i:right) {
            cout<<i<<" ";
        }
        cout<<endl;*/
        
        
        // all leaves would be the bottom
        vector<TreeNode*> leaf;
        helper(leaf, root);
        
        
        //cout<<leaf.size()<<endl;
        vector<int> res;
        res.push_back(root->val);
        std::copy(left.begin(), left.end(), back_inserter(res));
        //res.push_back(left.begin(), left.end());
        for (int i=0; i<leaf.size(); ++i) {
            if (leaf[i] == ll || leaf[i] == rr || leaf[i]==root)
                continue;
            res.push_back(leaf[i]->val);
        }
        std::copy(right.rbegin(), right.rend(), back_inserter(res));
        //res.push_back(right.rbegin(), right.rend());
        
        return res;
    }
    
    void helper(vector<TreeNode*>& leaf, TreeNode *root) {
        if (root==nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr) {
            leaf.push_back(root);
            return;
        }
        helper(leaf, root->left);
        helper(leaf, root->right);
    }
};

