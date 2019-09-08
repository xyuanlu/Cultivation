/*
 * 297. Serialize and Deserialize Binary Tree
 *
 */


#include <sstream> 
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
    string serialize(TreeNode* root) {
        string res;
        vector<TreeNode*> temp, next;
        temp.push_back(root);
        for(int i=0; i<temp.size();) {
            //cout<<"s"<<endl;
            TreeNode* cur = temp[i];
            //cout << "XXX: " << cur << endl;
            if (cur != nullptr) {
                res += std::to_string(cur->val) + " ";
                next.push_back(cur->left);
                next.push_back(cur->right);

            } else {
                res += "# ";
            }
            if (i == temp.size()-1) {
                //cout<<"next"<<next.size()<<endl;
                temp.swap(next);
                next.clear();
                i=0;
                continue;
            }
            ++i;
        }
        cout<<res<<endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root;
        std::istringstream iss(data);
        vector<string> nodes(std::istream_iterator<std::string>{iss},
                                 std::istream_iterator<std::string>());

        if (nodes.size()==0) return nullptr;
        
        vector<TreeNode*> cur, next;
        root = createTreeNode(nodes[0]);
        if (root == nullptr) {
            return root;
        } else {
            cur.push_back(root);
        }
        
        int i=1;
        for(int k=0; k<cur.size();) {
            TreeNode* it = cur[k];
            //cout<<it->val<<endl;
            TreeNode* temp = createTreeNode(nodes[i++]);
            it->left = temp;
            if (temp != nullptr) {
                next.push_back(temp);
            }
            temp = createTreeNode(nodes[i++]);
            it->right = temp;
            if (temp != nullptr) {
                next.push_back(temp);
            }
            if (k == cur.size()-1) {
                cout<<endl;
               cur = next;
               next.clear();
               k=0;
                continue;
            }
            ++k;
        }
        return root;
        
        
    }
    
private:
    TreeNode* 
    createTreeNode(const string& s) {
        //cout<<"creating" << s <<endl;
        if (s != "#") {
            return new TreeNode(stoi(s));
        } else {
            return nullptr;
        }
    }
    
    
    
    
    
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
