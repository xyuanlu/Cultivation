/*
 * 652. Find Duplicate Subtrees
 * Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees,
 * you only need to return the root node of any one of them.
 *
 * Two trees are duplicate if they have the same structure with same node values.
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        // root, left, right, id, count, 
        unordered_map<int, unordered_map<int, unordered_map<int, pair<int, int>>>> m;
        vector<TreeNode*> res;
        helper(m, res, root);
        return res;
    }
    
    
    // return the id of a subtree;
    int helper(unordered_map<int, unordered_map<int, 
               unordered_map<int, pair<int, int>>>>& m,
                vector<TreeNode*>& res, TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int lid, rid;
        lid = helper(m, res, root->left);
        rid = helper(m, res, root->right);
        // if this is a never seen subtree
        if (m.count(root->val) == 0 ||
            m[root->val].count(lid) == 0 ||
            m[root->val][lid].count(rid) ==0) {
            //cout<<"new"<<endl;
            m[root->val][lid][rid]= make_pair(++_count, 1);
            
        } else {
            //cout<<m[root->val][lid][rid].second<<endl;
            if (m[root->val][lid][rid].second==1)
                res.push_back(root);
            m[root->val][lid][rid].second++;
        }
        //cout<<root->val<<" "<<lid<<" "<<rid<<" "<<_count<<endl;
        return m[root->val][lid][rid].first;
    }
    
private:
    int _count = 0;
};
