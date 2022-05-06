/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        int carry = 0;
        auto p = &dummy;
        while (l1 && l2) {
            int tmp = carry + l1->val + l2->val;
            auto node = new ListNode(tmp%10);
            carry = tmp / 10;
            p->next = node;
            p = node;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            int tmp = carry + l1->val;
            auto node = new ListNode(tmp%10);
            carry = tmp / 10;
            p->next = node;
            p = node;
            l1 = l1->next;
        }
        while (l2) {
            int tmp = carry + l2->val;
            auto node = new ListNode(tmp%10);
            carry = tmp / 10;
            p->next = node;
            p = node;
            l2 = l2->next;
        }
        if (carry) {
            auto node = new ListNode(carry);
            p->next = node;
        }
        return dummy.next;
    }
};