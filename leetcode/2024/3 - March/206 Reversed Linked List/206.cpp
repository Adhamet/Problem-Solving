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
    ListNode* reverseList(ListNode* head) {
        vector<int> listVals;
        ListNode* travs = head;
        while(travs != nullptr) {
            listVals.push_back(travs->val);
            travs = travs->next;
        }

        ListNode* reverse = nullptr;
        ListNode* prevNode = reverse;
        for(auto itr = listVals.rbegin(); itr != listVals.rend(); ++itr) {
            ListNode* newNode = new ListNode(*itr);
            if (reverse == nullptr) reverse = newNode;
            else prevNode->next = newNode;
            prevNode = newNode;
        }
        if (prevNode != nullptr) prevNode->next = nullptr;

        return reverse;
    }
};