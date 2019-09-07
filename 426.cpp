/*
 *  426. Convert Binary Search Tree to Sorted Doubly Linked List
 *
 *    Traverse the tree using stack. link cur and previous.
 *    After stack is empty, prev will be the tail. Link head with tail.
 */
 
 /*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        stack<Node*> m;
        Node* head = nullptr;
        if(root == nullptr)
            return nullptr;
        Node *cur = root, *prev = nullptr;
        while(cur!=nullptr || !m.empty()) {
            if(cur!=nullptr ) {
                //cout<<cur->val<<endl;
                m.push(cur);
                cur=cur->left;
                continue;
            }
            
            if(!m.empty()) {
                cur = m.top();
                //cout<<cur->val<<endl;
                cur->left = prev;
                if(prev == nullptr) {
                    head = cur;
                } else {
                    prev->right = cur;
                }
                m.pop();
                prev = cur;
                if(cur->right != nullptr) {
                    cur = cur->right;
                } else {
                    cur = nullptr;
                }
            }
        }
        head -> left = prev;
        prev -> right = head;
        return head;
    }
};
