/*
 * 272. Closest Binary Search Tree Value II
 * Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.
 *
 * Given target value is a floating point.
 * You may assume k is always valid, that is: k ≤ total nodes.
 * You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
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
    
    /*
     * First we find the most cloest node to target and get the trace
     * The stack we have here is different from te stack
     * for inorder iterator
     */
    
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        stack<TreeNode*> s;
        double epsl = 0.00001;
        double minD = DBL_MAX;
        //1. find the cloest     ----- O(Log n)
        while(root!=nullptr) {
            s.push(root);
            cout<<root->val<<" ";
            minD = min(minD, abs(root->val - target));
            if (abs(root->val - target) < epsl) {
                break;
            } else if (root->val - target > epsl) {  // root > target
                root = root->left;
            } else {
                root = root->right;
            }
        }
        
        // The cloest must be in the trace
        while(!s.empty()) {
            if (abs(s.top()->val - target) >minD) {
                s.pop();
            } else {
                break;
            }
        }
        
        // Now s.top is the cloest
        //cout<<" : "<<s.top()->val<<endl;
        
        vector<int> res;
        stack<TreeNode*> prev, post;
        prev = post = s;
        
        // edit pre and post stack
        if (s.top()->val <target) {
            postNext(post);
        } else {
            prevNext(prev);
        }
        
        // compare the top of these stack, add one to res
        while(res.size() != k && (!prev.empty() || !post.empty())) {
            double aa = DBL_MAX;
            double bb = DBL_MAX;
            if (!prev.empty()) {
                aa = abs(target - prev.top()->val);
                
            } if (!post.empty()) {
                bb = abs(target - post.top()->val);
            }
            if (aa<bb) {
                //cout<<"1: "<<prev.top()->val<<endl;
                res.push_back(prev.top()->val);
                prevNext(prev);
            } else {
                //cout<<"2: "<<post.top()->val<<endl;
                res.push_back(post.top()->val);
                postNext(post);
            }
        }
        return res;
        
    }
    
    // post.top() always the next node
    void postNext(stack<TreeNode*>& s) {
        TreeNode *root = s.top();
        //s.pop();
        if(root->right != nullptr) {
            root = root->right;
            while(root!=nullptr) {
                s.push(root);
                root = root->left;
            }
        } else {
            while(!s.empty() && s.top()->val<=root->val) {
                s.pop();
            }
        }
        //cout<<"post: ";
        //if (!s.empty()) cout<<s.top()->val<<endl;
    }
    
    // prev.top() always the previous node
    void prevNext(stack<TreeNode*>& s) {
        TreeNode *root = s.top();
        //s.pop();
        if(root->left != nullptr) {
            root = root->left;
            while(root!=nullptr) {
                s.push(root);
                root = root->right;
            }
        } else {
            while(!s.empty() && s.top()->val>=root->val) {
                s.pop();
            }
        }
        //cout<<"prev: ";
        //if (!s.empty()) cout<<s.top()->val<<endl;
    }    
};

// Or we can do a O(n)
