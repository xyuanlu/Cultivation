/*
 * 863. All Nodes Distance K in Binary Tree
 * 
 *  We are given a binary tree (with root node root), a target node, and an integer value K.
 *
 * Return a list of the values of all nodes that have a distance K from the target node. 
 * The answer can be returned in any order.
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<TreeNode*> path;
        vector<TreeNode*> p{root};
        dfs(root, target, path, p);
        
        /*for(auto i:path) {
            cout<<i->val<<" ";
        }
        cout<<endl;*/
        
        vector<int> res;
        for(int i=0; i<path.size(); ++i) {
            int step = k-(path.size()-i-1);
            //cout<<step<<endl;
            if (step<0)
                continue;
            if (step ==0)
                res.push_back(path[i]->val);
            step--;
            queue<TreeNode*> q, n;
            if ((i==path.size()-1 || path[i]->left!=path[i+1]) && path[i]->left!=nullptr) {
                q.push(path[i]->left);
            }
            if ((i==path.size()-1 || path[i]->right!=path[i+1]) && path[i]->right!=nullptr) {
                q.push(path[i]->right);
            }
            while(!q.empty()) {
                if(step == 0) {
                    while(!q.empty()) {
                        res.push_back(q.front()->val);
                        q.pop();
                    }
                    break;
                }
                TreeNode *t = q.front();
                assert(t);
                //cout<<t->val<<endl;
                q.pop();
                if(t->left != nullptr) n.push(t->left);
                if(t->right != nullptr) n.push(t->right);
                if(q.empty()) {
                    q = n;
                    n = queue<TreeNode*>();
                    step--;
                }
            }
        }
        return res;
    }
    
    void dfs(TreeNode* root, TreeNode* target, vector<TreeNode*>& path, vector<TreeNode*>& p) {
        if(root == target) {
            //cout<<root->val<<endl;
            path = vector<TreeNode*>(p);
            return;
        }
        if(!path.empty())
            return;
        if(root->left != nullptr) {
            p.push_back(root->left);
            dfs(root->left, target, path, p);
            p.pop_back();
        }
        if(root->right!=nullptr) {
            p.push_back(root->right);
            dfs(root->right, target, path, p);
            p.pop_back();
        }
    }
};
