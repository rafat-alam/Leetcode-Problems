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
class FindElements {
    set<int> st;
public:
    void f(TreeNode* root) {
        int x = root->val;
        st.insert(x);

        if(root->left != NULL) {
            root->left->val = 2 * x + 1;
            f(root->left);
        }
        if(root->right != NULL) {
            root->right->val = 2 * x + 2;
            f(root->right);
        }
    }
    FindElements(TreeNode* root) {
        root->val = 0;
        f(root);
    }
    
    bool find(int target) {
        return st.count(target) != 0;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */