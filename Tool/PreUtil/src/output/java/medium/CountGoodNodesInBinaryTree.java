/**https://leetcode.com/problems/count-good-nodes-in-binary-tree/ */
//Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.
//Return the number of good nodes in the binary tree.


/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class CountGoodNodesInBinaryTree {
    public int goodNodes(TreeNode root) {
        return helper(root, Integer.MIN_VALUE);
        
    }
}

    