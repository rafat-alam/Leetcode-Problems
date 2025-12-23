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
    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        function<void (TreeNode*)> f = [&](TreeNode* root) -> void {
            if(root == NULL) return;
            if(root->val % 2 == 0) {
                if(root->left && root->left->left) sum += root->left->left->val;
                if(root->left && root->left->right) sum += root->left->right->val;
                if(root->right && root->right->left) sum += root->right->left->val;
                if(root->right && root->right->right) sum += root->right->right->val;
            }
            f(root->right);
            f(root->left);
        };
        f(root);
        return sum;
    }
};