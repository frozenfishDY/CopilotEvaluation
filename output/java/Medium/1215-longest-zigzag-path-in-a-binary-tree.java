/**https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/ */
//You are given the root of a binary tree.
//A ZigZag path for a binary tree is defined as follow:
//Choose any node in the binary tree and a direction (right or left).
//If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
//Change the direction from right to left or from left to right.
//Repeat the second and third steps until you can't move in the tree.
//Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).
//Return the longest ZigZag path contained in that tree.


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
class LongestZigzagPathInABinaryTree {
    public int longestZigZag(TreeNode root) {
        int[] max = new int[1];
        helper(root, max, true);
        return max[0];
        
    }
}

    