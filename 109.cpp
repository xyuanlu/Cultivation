/*
 * 109. Convert Sorted List to Binary Search Tree
 */
 
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        ListNode d(-1);
        d.next = head;
        ListNode *l = &d, *r = &d;
        while(r->next != nullptr && r->next->next!= nullptr) {
            l = l->next;
            r = r->next->next;
        }
        TreeNode *root = new TreeNode(l->next->val);
        
        r = l->next->next;
        l->next = nullptr;
        root->left = sortedListToBST(d.next);
        root->right = sortedListToBST(r);
        
        return root;
    }
};
