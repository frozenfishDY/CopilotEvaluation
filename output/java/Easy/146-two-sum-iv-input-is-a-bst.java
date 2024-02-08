/**https://leetcode.com/problems/two-sum-iv-input-is-a-bst/ */
//Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.


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
class TwoSumIvInputIsABst {
    public boolean findTarget(TreeNode root, int k) {
        if(root == null) return false;
        Set<Integer> set = new HashSet<>();
        return dfs(root, k, set);
        
        
        
    }
}

    