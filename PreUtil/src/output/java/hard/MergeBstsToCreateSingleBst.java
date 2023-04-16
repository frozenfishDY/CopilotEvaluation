/**https://leetcode.com/problems/merge-bsts-to-create-single-bst/ */
//You are given n BST (binary search tree) root nodes for n separate BSTs stored in an array trees (0-indexed). Each BST in trees has at most 3 nodes, and no two roots have the same value. In one operation, you can:
//Select two distinct indices i and j such that the value stored at one of the leaves of trees[i] is equal to the root value of trees[j].
//Replace the leaf node in trees[i] with trees[j].
//Remove trees[j] from trees.
//Return the root of the resulting BST if it is possible to form a valid BST after performing n - 1 operations, or null if it is impossible to create a valid BST.
//A BST (binary search tree) is a binary tree where each node satisfies the following property:
//Every node in the node's left subtree has a value strictly less than the node's value.
//Every node in the node's right subtree has a value strictly greater than the node's value.
//A leaf is a node that has no children.


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
class MergeBstsToCreateSingleBst {
    public TreeNode canMerge(List<TreeNode> trees) {
        Map<Integer, TreeNode> map = new HashMap<>();
        for(TreeNode node : trees){
            map.put(node.val, node);
        }
        for(TreeNode node : trees){
            if(node.left != null){
                if(!map.containsKey(node.left.val)){
                    return null;
                }
                node.left = map.get(node.left.val);
            }
            if(node.right != null){
                if(!map.containsKey(node.right.val)){
                    return null;
                }
                node.right = map.get(node.right.val);
            }
        }
        TreeNode root = null;
        for(TreeNode node : trees){
            if(node.left == null && node.right == null){
                if(root == null){
                    root = node;
                }else{
                    return null;
                }
            }
        }
        if(root == null){
            return null;
        }
        return dfs(root, map);
        
    }
}
     
    