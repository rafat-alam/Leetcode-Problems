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
    int i = 0;
    TreeNode* bstFromPreorder(vector<int>& a, int ma = INT_MAX) {
        if(i == a.size() || a[i] > ma) return NULL;
        TreeNode* root = new TreeNode(a[i++]);
        root->left = bstFromPreorder(a, root->val);
        root->right = bstFromPreorder(a, ma);
        return root;
    }
};