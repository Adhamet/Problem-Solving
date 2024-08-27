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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = dummy;

        while (curr) {
            int sum = 0;
            ListNode* runner = curr->next;
            while (runner) {
                sum += runner->val;
                if (sum == 0) {
                    curr->next = runner->next;
                }
                runner = runner->next;
            }
            curr = curr->next;
        }

        return dummy->next;
    }
};