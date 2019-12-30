/*
 * 1305. All Elements in Two Binary Search Trees
 * Given two binary search trees root1 and root2.
 *
 * Return a list containing all the integers from both trees sorted in ascending order.
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

/*
 * BST iteraor + merge
 */
class Solution {
public:
    stack<TreeNode*> s1, s2;
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        InitStack(s1, root1);
        InitStack(s2, root2);
        
        vector<int> res;
        while(!s1.empty() || !s2.empty()) {
            if (!s1.empty() && (s2.empty() || s1.top()->val < s2.top()->val)) {
                res.push_back(s1.top()->val);
                MoveNext(s1);
            } else {
                res.push_back(s2.top()->val);
                MoveNext(s2);
            }
        }
        return res;
    }
    
    void InitStack(stack<TreeNode*>& s, TreeNode* root) {
        while(root!=nullptr) {
            s.push(root);
            root=root->left;
        }
        
    }
    
    void MoveNext(stack<TreeNode*>& s) {
        TreeNode *cur = s.top();
        s.pop();
        if(cur->right!=nullptr) {
            cur = cur->right;
            InitStack(s, cur);
        }
    }
    
    
};
