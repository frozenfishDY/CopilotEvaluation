/**https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/ */
//Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.
//A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.


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
var maxAncestorDiff = function(root) {
    let result = 0;
    let dfs = function(node, min, max){
        if(node == null){
            return;
        }
        result = Math.max(result, Math.abs(node.val - min), Math.abs(node.val - max));
        min = Math.min(min, node.val);
        max = Math.max(max, node.val);
        dfs(node.left, min, max);
        dfs(node.right, min, max);
    }
    dfs(root, root.val, root.val);
    return result;
    
};

    