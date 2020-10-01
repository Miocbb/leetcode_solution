import tree

class TreeNode:
     def __init__(self, val=0, left=None, right=None):
         self.val = val
         self.left = left
         self.right = right

class Solution:
    def buildTree(self, preorder, inorder) -> TreeNode:
        """
        The `preorder` and `inorder` contains the whole tree.
        The `preorder[1: mid+1]` and `inorder[0:mid]` contains the whole tree
        of the `root.left`. So, this is the same sub-problem. Easy recursion
        problem.
        """
        if len(preorder) == 0:
            return None
        root = TreeNode(preorder[0])
        mid = inorder.index(preorder[0])
        # divide preorder and inorder at the same time.
        # root->left:
        # preorder[1: mid+1]: mid number of elements
        # inorder[0: mid]: mid number of elements
        root.left = self.buildTree(preorder[1:mid+1], inorder[:mid])
        root.right = self.buildTree(preorder[mid+1:], inorder[mid+1:])
        return root

t = tree.array_to_tree([2, 1, 3])
print(tree.tree_to_array(t))

preorder = [2, 1, 3]
inorder = [1, 2, 3]
s = Solution()
root = s.buildTree(preorder, inorder)
print(tree.tree_to_array(root))
