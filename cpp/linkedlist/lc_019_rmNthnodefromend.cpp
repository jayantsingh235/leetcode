/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *removeNode, *cur, *prev;
        int k = 0;
        if (!head)
            return head;
        removeNode = head;
        prev = NULL;
        cur = head;
        
        while (cur->next) {
            cur = cur->next;
            k++;
            if (k >= n) {
                prev = removeNode;
                removeNode = removeNode->next;
            }
        }
        //cout << cur->val << endl;
        //cout << prev->val << endl;
        //cout << removeNode->val << endl;
        if (prev == NULL) {
            head = removeNode->next;            
        } else {
            prev->next = removeNode->next;
        }
        delete removeNode;
        return head;
    }
};
