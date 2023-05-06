/**https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/ */
//Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes. More formally, the property root.val = min(root.left.val, root.right.val) always holds.
//Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.
//If no such second minimum value exists, output -1 instead.


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
class SecondMinimumNodeInABinaryTree {
    public int findSecondMinimumValue(TreeNode root) {
        if(root == null) return -1;
        int min = root.val;
        int res = Integer.MAX_VALUE;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        while(!queue.isEmpty()){
            TreeNode node = queue.poll();
            if(node.val > min){
                res = Math.min(res, node.val);
            }
            if(node.left != null){
                queue.offer(node.left);
                queue.offer(node.right);
            }
        }
        return res == Integer.MAX_VALUE ? -1 : res;
        
    }
}

    