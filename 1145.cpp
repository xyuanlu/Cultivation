/*
 * 1145. Binary Tree Coloring Game
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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        // Node x has at most 3 connected 'subtree'
        // If the size of one subtree is larger than the sum of
        // the other two, then its true.
        
        int s1, sl, sr;
        s1 = helper(root, sl, sr, x);
        
        cout<<s1<<" "<<sl<<" "<<sr<<endl; 
        s1 = s1-(sl+sr+1);
        vector<int> m = {s1, sl, sr};
        sort(m.begin(), m.end());
        return m[2]>m[0]+m[1];
    }
    
    int helper(TreeNode *cur, int& sl, int& sr, int x) {
        if (cur == nullptr) {
            return 0;
        }
        int l=0, r=0;
        l = helper(cur->left, sl, sr, x);
        r = helper(cur->right, sl, sr, x);
        if (cur->val ==x) {
            sl = l;
            sr = r;
        }
        return 1+l + r;
    }
    
    
};
