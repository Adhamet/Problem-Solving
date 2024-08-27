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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return false;
        
        ListNode *fsNode = head;
        ListNode *scNode = head->next;

        while(fsNode != scNode) {
            if(scNode == NULL || scNode->next == NULL)
                return false;
            fsNode = fsNode->next;
            scNode = scNode->next->next;
        }

        return true;
    }
};