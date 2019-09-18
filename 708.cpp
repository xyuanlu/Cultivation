/*
 * 708. Insert into a Cyclic Sorted List
 * 
 *  Given a node from a cyclic linked list which is sorted in ascending order,
 *  write a function to insert a value into the list such that it remains a cyclic
 *  sorted list. The given node can be a reference to any single node in the list,
 *  and may not be necessarily the smallest value in the cyclic list.
 */
 
 /*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(head == nullptr) {
            Node *t = new Node(insertVal);
            t->next = t;
            return t;
        }
        
        Node *cur = nullptr;
        while (cur != head) {
            if(cur == nullptr) {
                cur = head;
            }
            /*
             * 1. New node with in  3<= n (4) <=5
             * 2. New node should be placed at the the counter point
             *      a). Cur is the end & begin met point
             *      b). val > end &<begin
             * 3. We went a=through a circle, did not find correct place,
             *    then all value should be the same. We just place it before head.
             */
            if ((insertVal >= cur->val && insertVal <= cur->next->val)  // 1. 3<=n<=6
                || (cur->next->val < cur->val &&                       //  2.(a)
                    (insertVal>cur->val || insertVal<cur->next->val))  //  2.(b) val > end &<begin
                || cur->next == head){                                 //  3 
                // insert between cur and cur->next;
                
                Node *n = cur->next;
                Node *t = new Node(insertVal);
                cur->next = t;
                t->next = n;
                break;
            }
            cur = cur->next;
        }
        return head;
    }
};
