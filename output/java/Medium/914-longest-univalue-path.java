/**https://leetcode.com/problems/longest-univalue-path/ */
//Given the root of a binary tree, return the length of the longest path, where each node in the path has the same value. This path may or may not pass through the root.
//The length of the path between two nodes is represented by the number of edges between them.


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
class LongestUnivaluePath {
    public int longestUnivaluePath(TreeNode root) {
        int[] res = new int[1];
        helper(root, res);
        return res[0];
        
    }
}

    