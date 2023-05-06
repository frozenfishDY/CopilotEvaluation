/**https://leetcode.com/problems/binary-tree-tilt/ */
//Given the root of a binary tree, return the sum of every tree node's tilt.
//The tilt of a tree node is the absolute difference between the sum of all left subtree node values and all right subtree node values. If a node does not have a left child, then the sum of the left subtree node values is treated as 0. The rule is similar if the node does not have a right child.


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
class BinaryTreeTilt {
    public int findTilt(TreeNode root) {
        if(root == null) return 0;
        int[] ans = new int[1];
        dfs(root, ans);
        return ans[0];
        
        
    }
}

    