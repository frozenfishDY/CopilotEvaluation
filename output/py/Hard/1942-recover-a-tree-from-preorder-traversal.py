#https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/
#We run a preorder depth-first search (DFS) on the root of a binary tree.
#At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.
#If a node has only one child, that child is guaranteed to be the left child.
#Given the output traversal of this traversal, recover the tree and return its root.


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def recoverFromPreorder(self, traversal):
        """
        :type traversal: str
        :rtype: TreeNode
        """
        def get_depth(s):
            res = 0
            for c in s:
                if c == '-':
                    res += 1
                else:
                    break
            return res
        def get_val(s):
            res = 0
            for c in s:
                if c == '-':
                    break
                else:
                    res = res * 10 + int(c)
            return res
        def get_node(s):
            return TreeNode(get_val(s))
        def get_children(s):
            res = []
            i = 0
            while i < len(s):
                if s[i] == '-':
                    j = i
                    while j < len(s) and s[j] == '-':
                        j += 1
                    k = j
                    while k < len(s) and s[k] != '-':
                        k += 1
                    res.append(s[j:k])
                    i = k
                else:
                    i += 1
            return res
        def get_tree(s):
            if not s:
                return None
            root = get_node(s)
            children = get_children(s)
            if not children:
                return root
            i = 0
            while i < len(children):
                j = i
                while j < len(children) and get_depth(children[j]) > get_depth(children[i]):
                    j += 1
                root.left = get_tree(children[i])
                if j < len(children):
                    root.right = get_tree(children[j])
                i = j
            return root
        return get_tree(traversal)
        
        
    