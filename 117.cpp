/*
 * 117. Populating Next Right Pointers in Each Node II
 */
 
 /*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        // BFS a Binary Tree
        queue<Node*> q, qq;
        if(root == nullptr)
            return nullptr;
        q.push(root);
        Node* prev = nullptr;
        
        while(!q.empty()) {
            Node* n = q.front();
            q.pop();
            if(n->left != nullptr) {
                qq.push(n->left);
            }
            if(n->right != nullptr) {
                qq.push(n->right);
            }
            if(prev != nullptr) {
                prev->next = n;
            }
            prev = n;
            if(q.empty()) {
                q=qq;
                qq = queue<Node*>();
                n->next = nullptr;
                prev = nullptr;
            }
        }
        return root;
    }
};
