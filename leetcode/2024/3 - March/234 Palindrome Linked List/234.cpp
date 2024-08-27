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
    bool isPalindrome(ListNode* head) {
        ListNode* travs = head;
        string norm, reversed;
        while(travs != nullptr) {
            norm.push_back(travs->val + '0');
            travs = travs->next;
        }
        reversed = norm;
        reverse(reversed.begin(),reversed.end());
        if(norm == reversed) return true;
        else return false;
    }
};
