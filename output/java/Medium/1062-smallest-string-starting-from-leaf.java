/**https://leetcode.com/problems/smallest-string-starting-from-leaf/ */
//You are given the root of a binary tree where each node has a value in the range [0, 25] representing the letters 'a' to 'z'.
//Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.
//As a reminder, any shorter prefix of a string is lexicographically smaller.
//For example, "ab" is lexicographically smaller than "aba".
//A leaf of a node is a node that has no children.


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
class SmallestStringStartingFromLeaf {
    public String smallestFromLeaf(TreeNode root) {
        if(root == null){
            return "";
        }
        String[] result = new String[1];
        result[0] = "z";
        dfs(root, "", result);
        return result[0];
        
        
    }
}

    