/**https://leetcode.com/problems/deepest-leaves-sum/ */
//Given the root of a binary tree, return the sum of values of its deepest leaves.


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
var deepestLeavesSum = function(root) {
    let maxDepth = 0;
    let sum = 0;
    let dfs = function(node, depth){
        if(node == null){
            return;
        }
        if(node.left == null && node.right == null){
            if(depth > maxDepth){
                maxDepth = depth;
                sum = node.val;
            }else if(depth == maxDepth){
                sum += node.val;
            }
        }
        dfs(node.left, depth + 1);
        dfs(node.right, depth + 1);
    }
    dfs(root, 0);
    return sum;
    
};

    