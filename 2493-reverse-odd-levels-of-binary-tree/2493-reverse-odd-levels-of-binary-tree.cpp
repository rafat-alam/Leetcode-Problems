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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while(!q.empty()) {
            vector<TreeNode*> temp;
            vector<int> val;
            while(!q.empty()) {
                TreeNode* top = q.front();
                q.pop();
                if(top->left) {
                    temp.push_back(top->left);
                    val.push_back(top->left->val);
                }
                if(top->right) {
                    temp.push_back(top->right);
                    val.push_back(top->right->val);
                }
            }

            if(i) reverse(val.begin(), val.end());

            for(int i = 0; i < val.size(); i++) {
                temp[i]->val = val[i];
                q.push(temp[i]);
            }
            i = 1 - i;
        }
        return root;
    }
};