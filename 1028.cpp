/*
 * 1028. Recover a Tree From Preorder Traversal 
 * We run a preorder depth first search on the root of a binary tree.
 *
 * At each node in this traversal, we output D dashes (where D is the depth of this node),
 * then we output the value of this node.  (If the depth of a node is D, the depth of its
 * immediate child is D+1.  The depth of the root node is 0.)
 *
 * If a node has only one child, that child is guaranteed to be the left child.
 * 
 * Given the output S of this traversal, recover the tree and return its root.
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
    class Pair{
    public:
        TreeNode *t;
        int d;
        
        Pair(TreeNode *tt, int dd): t(tt), d(dd) {};
        
    };
    
    TreeNode* recoverFromPreorder(string S) {
        if (S.size()==0)
            return nullptr;
        
        int count = 0;
        int i=0, num=0;
        while(i<S.size() && isdigit(S[i])) {
            num = num*10 + S[i]-'0';
            ++i;
        }
        TreeNode *root = new TreeNode(num);
        //TreeNode *cur = root, *prev = root;
        stack<Pair> m;
        m.push(Pair(root, 0));
        
        while (i<S.size()) {
            while (S[i]=='-') {
                ++count;
                ++i;
            }
            num=0;
            while(i<S.size() && isdigit(S[i])) {
                num = num*10 + S[i]-'0';
                ++i;
            }
            //cout<<count<<" "<<num<<endl;
            while (count < m.top().d+1) {
                m.pop();
            }
            TreeNode *n = new TreeNode(num);
            if (m.top().t->left ==nullptr) {
                m.top().t->left = n;
            } else {
                m.top().t->right = n;
            }
            m.push(Pair(n, count));
            count = 0;
            //++i;
        }
        return root;
    }
};




