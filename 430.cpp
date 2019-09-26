/*
 * 430. Flatten a Multilevel Doubly Linked List
 */
 /*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        Node *cur = head, *res = head;
        helper(head);
        Node *i = head;
        /*while(i!=nullptr) {
            cout<<i->val<<" ";
            i=i->next;
        }*/
        return head;
    }
    
    // Remember to update each "turn" point. 
    Node* helper(Node* head) {
        Node *cur = head;
        while(cur!= nullptr) {
            cout<<cur->val<<endl;
            Node *n = cur->next;
            if (cur->child != nullptr) {
                //cout<<"child "<<cur->child->val<<endl;
                cur->next = cur->child;      // <----
                cur->child->prev = cur;      // <------
                Node *last = helper(cur->child);
                //cout<<"helper return"<<last->val<<endl;
                last->next = n;
                if (n!= nullptr)
                    n->prev = last;              // <-----
                cur->child = nullptr;
                cur = last;                     // <------ We have visited all child, update cur
                //cout<<cur->val<<" cur->next "<<cur->next->val<<endl;
            }
            if(n==nullptr){
                break;
            }
            cur = n;
        }
        return cur;
    }
};



