/*
 * 222. Count Complete Tree Nodes
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
    int countNodes(TreeNode* root) {
        if (root==nullptr)
            return 0;
        //1. determine the level
        TreeNode * cur = root;
        int lev = 0;
        while(cur!=nullptr) {
            lev++;
            cur = cur->left;
        }
        
        //2. The left and right [) range of last level
        int l = pow(2, lev-1);
        int r = pow(2, lev);
        
        cout<<l<<" "<<r<<endl;
        
        //3. Find the last node in the bottom level
        // TTTFF Find te last T
        int c = helper(root, l, r);
        cout<<c<<endl;
        
        // 4. Compute the res
        return pow(2, lev-1)-1 + (c-l+1);
    }
    
    // Find c using bs of node number [l, r)
    int helper(TreeNode *root, int l, int r) {
        int m;
        while(r>l+1) {
            m = l + (r-l)/2;
            //cout<<m<<endl;
            if (contains(root, m)) {
                l = m;
            } else {
                r=m;
            }
        }
        return l;
    }
    
    bool contains(TreeNode *root, int v) {
        //cout<<"v "<<v<<endl;
        stack<int> m;
        while(v/2>0) {
            m.push(v%2);
            v=v/2;
        }
        
        TreeNode *cur = root;
        while(cur!=nullptr && !m.empty()) {
            int t = m.top();
            m.pop();
            //cout<<t<<" "<<cur->val<<endl;
            if (t==0) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        return m.empty() && cur!=nullptr;
    }
};
=
