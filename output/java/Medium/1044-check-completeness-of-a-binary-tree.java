/**https://leetcode.com/problems/check-completeness-of-a-binary-tree/ */
//Given the root of a binary tree, determine if it is a complete binary tree.
//In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.


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
class CheckCompletenessOfABinaryTree {
    public boolean isCompleteTree(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        boolean flag = false;
        while(!q.isEmpty()){
            TreeNode node = q.poll();
            if(node == null){
                flag = true;
            }else{
                if(flag){
                    return false;
                }
                q.add(node.left);
                q.add(node.right);
            }
        }
        return true;
        
    }
}

    