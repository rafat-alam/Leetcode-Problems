/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int c = 0;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            queue<TreeNode*> tmp;
            int sum = 0;
            while(!q.empty()) {
                if(q.front()->left) tmp.push(q.front()->left);
                if(q.front()->right) tmp.push(q.front()->right);
                sum += q.front()->val;
                q.pop();
            }
            while(!tmp.empty()) {
                q.push(tmp.front());
                tmp.pop();
            }
            if(q.empty()) c = sum;
        }

        return c;
    }
};