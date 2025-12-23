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
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;

        function<pair<int, int> (TreeNode*)> f = [&](TreeNode* root) -> pair<int, int> {
            if(root == NULL) return {0, 0};
            auto [la, lb] = f(root->left);
            auto [ra, rb] = f(root->right);
            
            int sum = la + ra + root->val;
            int num = lb + rb + 1;

            if((sum / num) == root->val) ans++;

            return {sum, num};
        };

        f(root);

        return ans;
    }
};