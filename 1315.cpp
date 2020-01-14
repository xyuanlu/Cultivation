/*
 * 1315. Sum of Nodes with Even-Valued Grandparent
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
    int res;
    class P{
    public:
        TreeNode *next;
        bool n;
    };
    int sumEvenGrandparent(TreeNode* root) {
        res = 0;
        if (root == nullptr)
            return 0;
        queue<P> q;
        q.push({root, false});
        while(!q.empty()) {
            P t = q.front();
            q.pop();
            if (t.next->left != nullptr) {
                if(t.n) {
                    res+= t.next->left->val;
                }
                if (t.next->val %2 ==0) {
                    q.push({t.next->left, true});
                } else {
                    q.push({t.next->left, false});
                }
            }
            if (t.next->right != nullptr) {
                if(t.n) {
                    res+=t.next->right->val;
                }
                if (t.next->val %2 ==0) {
                    q.push({t.next->right, true});
                } else {
                    q.push({t.next->right, false});
                }
            }
        }
        return res;
    }
    
 
};
