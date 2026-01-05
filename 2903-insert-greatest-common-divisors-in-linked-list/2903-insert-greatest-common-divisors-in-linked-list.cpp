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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* ff = head;
        ListNode* ss = head->next;

        while(ss != NULL) {
            ff->next = new ListNode(__gcd(ff->val, ss->val));
            ff->next->next = ss;
            ff = ss;
            ss = ss->next;
        }

        return head;
    }
};