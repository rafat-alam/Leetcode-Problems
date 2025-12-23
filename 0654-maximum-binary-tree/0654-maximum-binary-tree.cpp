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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        function<TreeNode* (int, int)> f = [&](int l, int r) -> TreeNode* {
            if(l > r) return NULL;

            int ma = *max_element(nums.begin() + l, nums.begin() + r + 1);
            TreeNode* root = new TreeNode(ma);

            int idx = -1;
            for(int i = l; i <= r; i++) {
                if(nums[i] == ma) idx = i;
            }

            root->left = f(l, idx - 1);
            root->right = f(idx + 1, r);

            return root;
        };

        return f(0, nums.size() - 1);
    }
};