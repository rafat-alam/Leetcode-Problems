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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int l = 0, r = n - 1, u = 0, d = m - 1;
        vector<vector<int>> ans(m, vector<int> (n, -1));

        while(1) {
            if(u > d) break;

            for(int i = l; i <= r; i++) {
                if(head != NULL) {
                    ans[u][i] = head->val;
                    head = head->next;
                }
            }

            u++;

            if(l > r) break;

            for(int i = u; i <= d; i++) {
                if(head != NULL) {
                    ans[i][r] = head->val;
                    head = head->next;
                }
            }

            r--;

            if(u > d) break;

            for(int i = r; i >= l; i--) {
                if(head != NULL) {
                    ans[d][i] = head->val;
                    head = head->next;
                }
            }

            d--;

            if(l > r) break;

            for(int i = d; i >= u; i--) {
                if(head != NULL) {
                    ans[i][l] = head->val;
                    head = head->next;
                }
            }

            l++;
        }

        return ans;
    }
};