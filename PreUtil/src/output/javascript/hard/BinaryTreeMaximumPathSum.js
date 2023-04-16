/**https://leetcode.com/problems/binary-tree-maximum-path-sum/ */
//A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
//The path sum of a path is the sum of the node's values in the path.
//Given the root of a binary tree, return the maximum path sum of any non-empty path.


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
var maxPathSum = function(root) {
    let max = -Infinity;
    let dfs = function(node){
        if(node === null){
            return 0;
        }
        let left = Math.max(dfs(node.left), 0);
        let right = Math.max(dfs(node.right), 0);
        max = Math.max(max, left + right + node.val);
        return Math.max(left, right) + node.val;
    }
    dfs(root);
    return max;
    
};

    