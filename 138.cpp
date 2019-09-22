/*
 * 138. Copy List with Random Pointer
 */
 
 /*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        // cur-next = newNode, newNode->next = next;
        
        Node nn(-1);
        Node *dummy = &nn;
        dummy->next = head;
        Node *cur = head;
        
        // Do dummy -> n1->dupN1->n2->dupN2
        while(cur!= nullptr) {
            Node* next = cur->next;
            Node *n = new Node(cur->val);
            cur->next = n;
            n->next = next;
            n->random = nullptr;
            cur = next;
        }
        
        /*
        //print the duplicated list/
        Node *temp = dummy;
        while(temp!=nullptr) {
            cout<<temp->val<<" ";
            if(temp->random != nullptr) {
                cout<<"("<<temp->random->val<<") ";
            }
            temp=temp->next;
        }cout<<endl;
        */
        
        // Copy origioanl random pointer to new lists's
        cur = dummy->next;
        while(cur!=nullptr) {
            Node *n = cur->next;  // new Node
            cout<<cur->val<<" "<<n->val;
            Node *ran = cur->random;
            if(ran!=nullptr) {
                cout<<"("<<ran->val<<")";
                n->random = ran->next;
            }
            cout<<endl;
            //cur->next = n->next;
            cur = n->next;
            //prev->next = n;
            //prev = n;
        }
        
        
        // reverse origional list
        cur = head;
        Node *prev = dummy;
        while(cur!=nullptr) {
            Node *n = cur->next;
            cur->next = n->next;
            cur = cur->next;
            prev->next = n;
            prev = n;
        }
        
        /*
        print new list
        temp = dummy;
        while(temp!=nullptr) {
            cout<<temp->val<<" ";
            if(temp->random != nullptr) {
                cout<<"("<<temp->random->val<<") ";
            }
            temp=temp->next;
        }
        // print origional list
        cout<<"xx"<<endl;
        temp = head;
        while(temp!=nullptr) {
            cout<<temp->val<<" ";
            if(temp->random != nullptr) {
                cout<<"("<<temp->random->val<<") ";
            }
            temp=temp->next;
        }
        */
        return dummy->next;
    }
};
