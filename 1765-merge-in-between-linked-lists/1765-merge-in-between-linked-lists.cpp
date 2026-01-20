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
        ListNode* temp = list1;
        for(int i = 0; i < a - 1; i++) {
            temp = temp->next;
        }
        ListNode* rem = temp->next;
        temp->next = list2;
        for(int i = 0; i < b - a; i++) {
            rem = rem->next;
        }
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = rem->next;
        return list1;
    }
};