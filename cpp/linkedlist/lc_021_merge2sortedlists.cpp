/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *result, *cur, *t1, *t2;
        result = NULL;
        cur = NULL;
        if (!l1 && !l2)
            return result;
        if (!l2)
            return l1;
        if (!l1)
            return l2;
        t1 = l1;
        t2 = l2;
        while (t1 && t2) {
            if (t1->val < t2->val) {
                if (!result) {
                    result = new ListNode(t1->val);
                    cur = result;
                } else {
                    cur->next = new ListNode(t1->val);
                    cur = cur->next;
                }
                t1 = t1->next;
            } else if (t1->val == t2->val) {
                if (!result) {
                    result = new ListNode(t1->val);
                    result->next = new ListNode(t2->val);
                    cur = result->next;
                } else {
                    cur->next = new ListNode(t1->val);
                    cur->next->next = new ListNode(t2->val);
                    cur = cur->next->next;
                }
                t1 = t1->next;
                t2 = t2->next;
            } else {
                if (!result) {
                    result = new ListNode(t2->val);
                    cur = result;
                } else {
                    cur->next = new ListNode(t2->val);
                    cur = cur->next;
                }
                t2 = t2->next;
            }
        }
        if (t1) {
            cur->next = t1;
        } else if (t2) {
            cur->next = t2;
        }
        return result;
    }
};
