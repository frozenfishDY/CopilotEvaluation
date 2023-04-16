/**https://leetcode.com/problems/longest-univalue-path/ */
//Given the root of a binary tree, return the length of the longest path, where each node in the path has the same value. This path may or may not pass through the root.
//The length of the path between two nodes is represented by the number of edges between them.


/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var longestUnivaluePath = function(root) {
    let max = 0;
    function dfs(node){
        if(node == null){
            return 0;
        }
        let left = dfs(node.left);
        let right = dfs(node.right);
        let leftPath = 0;
        let rightPath = 0;
        if(node.left != null && node.left.val == node.val){
            leftPath = left + 1;
        }
        if(node.right != null && node.right.val == node.val){
            rightPath = right + 1;
        }
        max = Math.max(max, leftPath + rightPath);
        return Math.max(leftPath, rightPath);
    }
    dfs(root);
    return max;
    
};

    