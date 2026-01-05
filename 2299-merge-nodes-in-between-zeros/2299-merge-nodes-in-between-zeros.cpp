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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head->next;
        ListNode* lz = head;
        int val = 0;
        while(temp != NULL) {
            if(temp->val == 0) {
                temp->val = val;
                val = 0;
                lz->next = temp;
                lz = temp;
            } else {
                val += temp->val;
            }
            temp = temp->next;
        }
        return head->next;
    }
};