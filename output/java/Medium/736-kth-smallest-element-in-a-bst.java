/**https://leetcode.com/problems/kth-smallest-element-in-a-bst/ */
//Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.


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
class KthSmallestElementInABst {
    public int kthSmallest(TreeNode root, int k) {
        int left = countNodes(root.left);
        if(left == k - 1){
            return root.val;
        }else if(left > k - 1){
            return kthSmallest(root.left, k);
        }else{
            return kthSmallest(root.right, k - left - 1);
        }
        
        
    }
}

    