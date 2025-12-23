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
        function<void (TreeNode*, TreeNode*, int)> f = [&](TreeNode* left, TreeNode* right, int i) -> void {
            if(left == NULL) return;
            if(i) swap(left->val, right->val);
            f(left->left, right->right, 1 - i);
            f(left->right, right->left, 1 - i);
        };

        f(root->left, root->right, 1);
        return root;
    }
};