/*
 * 61. Rotate List
 * Given a linked list, rotate the list to the right by k places, where k is non-negative.
 *
 * Input: 1->2->3->4->5->NULL, k = 2
 * Output: 4->5->1->2->3->NULL
 * 
 * Input: 0->1->2->NULL, k = 4
 * Output: 2->0->1->NULL
 */
 
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || head==nullptr)
            return head;
        ListNode dh(-1);
        dh.next = head;
        ListNode *lastNode = head;
        
        // count the size
        int size = 0;
        ListNode *cur = &dh;
        while(cur->next!=nullptr) {
            cur=cur->next;
            size++;
        }
        lastNode = cur;
        
        k=k%size;
        if(k==0)
            return head;
        // isolate the first size-k 
        cur = head;
        k=size-k;
        while(k>1) {
            cur=cur->next;
            k--;
        }
        ListNode dh2(-1);
        dh2.next = cur->next;
        cur->next = nullptr;
        cout<<cur->val<<endl;
        
        // put the second half part to begin;
        lastNode->next = dh.next;
        
        return dh2.next;
    }
    
};
