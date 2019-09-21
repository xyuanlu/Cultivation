/*
 * 449. Serialize and Deserialize BST
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
class Codec {
public:

    // Encodes a tree to a single string.
    // [1, 2, 3,#, 4, 5, #]
    string serialize(TreeNode* root) {
        string res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode *t = q.front();
            q.pop();
            if(t == nullptr) {
                res += "#,";
            } else {
                res += to_string(t->val);
                res += ",";
                q.push(t->left);
                q.push(t->right);
            }
        }
        cout<<res<<endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes = split(data);
        if(nodes[0] == "#")
            return nullptr;
        TreeNode *root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> q;
        q.push(root);
        int idx = 1;
        while(!q.empty() || idx<nodes.size()) {
            TreeNode *t = q.front();
            q.pop();
            
            TreeNode *left = nullptr;
            if(nodes[idx] != "#"){
                left = new TreeNode(stoi(nodes[idx]));
                q.push(left);
            }
            t->left = left;
            ++idx;
            
            TreeNode *right = nullptr;
            if(nodes[idx] != "#"){
                right = new TreeNode(stoi(nodes[idx]));  
                q.push(right);
            }
            t->right = right;
            ++idx; 
        }
        return root;
        
        
    }
    
private:
    vector<string> split(const string& s) {
        int prev = 0;
        vector<string> res;
        for(int i=0; i<s.size(); ++i) {
            if(s[i] == ',') {
                res.push_back(s.substr(prev, i-prev));
                prev = i+1;
            }
        }
        return res;
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
