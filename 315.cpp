/*
 * 315. Count of Smaller Numbers After Self
 */
 
class Solution {
public:
    class Node{
    public:
        int val;
        Node *left, *right;
        int occ, lc;
        
        Node(int v){
            val = v;
            left = right = nullptr;
            lc = 0;
            occ = 1;
        }
        
        ~Node(){
            if(left != nullptr)
                delete left;
            if(right != nullptr)
                delete right;
        }
    };
    
    Node *root;
    vector<int> countSmaller(vector<int>& nums) {
        reverse(nums.begin(), nums.end());
        vector<int> res(nums.size(), 0);
        if(nums.size()==0)
            return res;
        
        root = new Node(nums[0]);
        
        for(int i=1; i<nums.size(); ++i) {
            int temp=0;
            helper(root, nums[i], temp);
            res[i] = temp;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    void helper(Node *root, int k, int& res) {
        if (root == nullptr) {
            return;
        } else if (root->val == k) {
            root->occ +=1;
            res += root->lc;
            return;
        } else if (root->val > k) {
            root->lc +=1;
            if (root->left == nullptr) {
                root->left = new Node(k); 
            } else 
                helper(root->left, k, res);
        } else {  // root->val < k
            res += root->lc + root->occ;
            if (root->right == nullptr) {
                root->right = new Node(k);
            } else 
                helper(root->right, k, res);
        }
        
    }
    
    ~Solution() {
        delete root;
    }
};
