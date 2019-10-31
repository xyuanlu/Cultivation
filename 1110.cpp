/*
 * 1110. Delete Nodes And Return Forest
 * Given the root of a binary tree, each node in the tree has a distinct value.
 *
 * After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).
 *
 * Return the roots of the trees in the remaining forest.  You may return the result in any order.
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> m;
        for(int i:to_delete) {
            m.insert(i);
        }
        vector<TreeNode*> res;
        helper(res, root, m, false);
        return res;
    }
    
    bool helper(vector<TreeNode*>& res, TreeNode* root,
                unordered_set<int> m, bool p /*parent in res*/) {
        if (root==nullptr) 
            return true;
        if (m.find(root->val) == m.end()) {
            if(!p)
                res.push_back(root);
            p=true;
        } else {
            //m.erase(root->val);
            p = false;
        }
        if (!helper(res, root->left, m, p)) {
            root->left = nullptr;
        }
        if (!helper(res, root->right, m, p)) {
            //cout<<root->val<<endl;
            root->right = nullptr;
        }
        return p;
    }
};
