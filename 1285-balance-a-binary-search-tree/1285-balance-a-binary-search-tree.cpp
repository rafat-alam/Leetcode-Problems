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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> preorder;

        function<void (TreeNode*)> f = [&] (TreeNode* root) -> void {
            if(root == NULL) return;
            f(root->left);
            preorder.push_back(root->val);
            f(root->right);
        };

        f(root);

        function<TreeNode* (int, int)> _f = [&] (int st, int end) -> TreeNode* {
            if(st > end) return NULL;
            int mid = (st + end) / 2;
            TreeNode* root = new TreeNode(preorder[mid]);
            root->left = _f(st, mid - 1);
            root->right = _f(mid + 1, end);
            return root;
        };

        return _f(0, preorder.size() - 1);
    }
};