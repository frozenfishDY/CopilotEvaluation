/**https://leetcode.com/problems/minimum-absolute-difference-in-bst/ */
//Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.


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
var getMinimumDifference = function(root) {
    let min = Infinity;
    let prev = null;
    function dfs(root){
        if(root == null){
            return;
        }
        dfs(root.left);
        if(prev != null){
            min = Math.min(min, root.val - prev);
        }
        prev = root.val;
        dfs(root.right);
    }
    dfs(root);
    return min;
    
};

    