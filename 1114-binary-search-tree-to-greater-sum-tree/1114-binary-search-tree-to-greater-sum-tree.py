# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorder(self, sum, root: Optional[TreeNode]):
        if not root:
            return
        self.postorder(sum, root.right)
        root.val += sum[0]
        sum[0] = root.val
        self.postorder(sum, root.left)

    def bstToGst(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        sum = [0]
        self.postorder(sum, root)
        return root