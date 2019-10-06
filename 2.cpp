/*
 * 2. Add Two Numbers
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        
        ListNode head(-1);
        ListNode *cur1 = l1, *cur2 = l2, *cur = &head;

        while(cur1 != nullptr || cur2 != nullptr) {
            int a=0, b=0;
            if (cur1 != nullptr) {
                a = cur1->val;
                cur1 = cur1->next;
            }
            if (cur2 != nullptr) {
                b = cur2->val;
                cur2 = cur2->next;
            }
            //cout<<a<<" "<<b<<" "<<(a+b+carry)/10<<endl;
            ListNode *n = new ListNode((a+b+carry)%10);
            cur->next = n;
            cur = n;
            
            carry = (a+b+carry)/10;
        }
        
        if(carry !=0) {
            ListNode *n = new ListNode(carry);
            cur->next = n;
        }
        
        return head.next;
    }
};
