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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* beforeA = list1;
        for (int i = 0; i < a-1; i++) beforeA = beforeA->next;
        ListNode* afterB = beforeA;
        for (int i = a-1; i <= b; i++) afterB = afterB->next;

        beforeA->next = list2;

        ListNode* endOfList2 = list2;
        while (endOfList2->next != nullptr) endOfList2 = endOfList2->next;
        endOfList2->next = afterB;

        return list1;
    }
};