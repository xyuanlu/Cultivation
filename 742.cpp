/*
 * 742. Closest Leaf in a Binary Tree
 * Given a binary tree where every node has a unique value, and a target key k,
 * find the value of the nearest leaf node to target k in the tree.
 *
 * Here, nearest to a leaf means the least number of edges travelled on the binary
 * tree to reach any leaf of the tree. Also, a node is called a leaf if it has no children.
 *
 * In the following examples, the input tree is represented in flattened form row by row.
 * The actual root tree given will be a TreeNode object.
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
    int findClosestLeaf(TreeNode* root, int k) {
        // Convert the tree to a general graph, and do a breadth-first search
        
        // 1. build the edges
        unordered_map<TreeNode*, vector<TreeNode*>> e;
        TreeNode *K;
        K = helper(e, root, k);
        //cout<<K->val<<endl;
        
        // 2. bfs
        queue<TreeNode*> q, qq;
        q.push(K);
        unordered_set<int> v;
        while(!q.empty()) {
            TreeNode* t = q.front();
            if(t->left == nullptr && t->right == nullptr) {
                return t->val;
            }
            //cout<<"t "<<t->val<<endl;
            v.insert(t->val);
            q.pop();
            for(int i=0; i<e[t].size(); ++i) {
                if (v.find(e[t][i]->val)==v.end()) {
                    qq.push(e[t][i]);
                }
            }
            if (q.size()==0) {
                q = qq;
                qq = queue<TreeNode*>();
            }
        }
        return k;
        
    }
    
    TreeNode* helper(unordered_map<TreeNode*, vector<TreeNode*>>& e,
                TreeNode* root, int k) {
        TreeNode* res = nullptr;
        if (root==nullptr)
            return res;
        
        if(root->val == k) {
            //cout<<root->val<<" "<<k<<endl;
            res = root;
        }
        
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        
        if(left!=nullptr) {
            e[root].push_back(left);
            e[left].push_back(root);
            TreeNode *t1 = helper(e, left, k);
            if (t1) res = t1;
        }
        if(right!=nullptr) {
            e[root].push_back(right);
            e[right].push_back(root);
            TreeNode *t2 = helper(e, right, k);
            if (t2) res = t2;
        }
        
        return res;
    }
};
