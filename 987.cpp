/*
  987. Vertical Order Traversal of a Binary Tree
  Given a binary tree, return the vertical order traversal of its nodes values.

  For each node at position (X, Y), its left and right children respectively will
  be at positions (X-1, Y-1) and (X+1, Y-1).

  Running a vertical line from X = -infinity to X = +infinity, whenever the vertical
  line touches some nodes, we report the values of the nodes in order from top to bottom
  (decreasing Y coordinates).

  If two nodes have the same position, then the value of the node that is reported first
  is the value that is smaller.

  Return an list of non-empty reports in order of X coordinate.  Every report will have a
  list of values of nodes.
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
    class N{
    public:
        TreeNode* node;
        int x;
        int y;
        
        N(TreeNode* n, int xx, int yy): node(n), x(xx), y(yy) {};
        
        bool operator<(const N& nn) const{
            if (this->x == nn.x)
                return node->val < nn.node->val;
            else 
                return x < nn.x;
        }
        
    };
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        N r(root, 0, 0);  // root at level 0.
        map<int, set<N>> res;                      // N is small it is ok to use object here.
        
        queue<N> q;
        q.push(r);
        while(!q.empty()) {
            N *cur = &q.front();
            int xx = cur->x;
            int yy = cur->y;
            res[yy].insert(*cur);
            q.pop();
            if(cur->node->left != nullptr) {
                N rl(cur->node->left, xx+1, yy-1);     // q.push will do a copy
                q.push(rl);
            }
            if(cur->node->right != nullptr) {
                N rr(cur->node->right, xx+1, yy+1);
                q.push(rr);
            }
        }
        
        vector<vector<int>> result;
        for(auto i:res) {
            vector<int> tmp;
            for(auto v:i.second) {
                tmp.push_back(v.node->val);
            }
            result.push_back(tmp);
        }
        return result;
    }
};
