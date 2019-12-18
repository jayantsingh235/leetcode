/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
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
private:
    void addCarryToList (ListNode **l, int carry) {
        int sum = 0;
        ListNode *t = *l;
        while (carry) {
            sum = t->val + carry;
            carry = sum / 10;
            t->val = sum % 10;
            if (t->next) {                                                                                                              t = t->next;                                                                                                        } else {                                                                                                                    if (carry) {                                                                                                                t->next = new ListNode (carry);                                                                                         t = t->next;                                                                                                            carry = 0;                                                                                                          }                                                                                                                   }                                                                                                                   }                                                                                                                   }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry, sum;
        ListNode *t1, *t2, *cur, *cur2;
        ListNode *answer = new ListNode (10);
        t1 = l1;
        t2 = l2;
        cur2 = cur = NULL;
        carry = 0;
        while (t1 && t2) {
            sum = carry + t1->val + t2->val;
            carry = sum / 10;
            if (cur == NULL) {
                cur = new ListNode (sum % 10);
                cur2 = cur;
            } else {
                cur->next = new ListNode (sum % 10);
                cur = cur->next;
            }
            t1 = t1->next;
            t2 = t2->next;
        }
        if (t1) {
            addCarryToList (&t1, carry);
            cur->next = t1;
        } else if (t2) {
            addCarryToList (&t2, carry);
            cur->next = t2;
        } else {
            if (carry) {
                cur->next = new ListNode (carry);
                cur = cur->next;
            }
        }
        return cur2;
    }
};
