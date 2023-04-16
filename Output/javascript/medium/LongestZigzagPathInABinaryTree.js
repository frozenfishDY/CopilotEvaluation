/**https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/ */
//You are given the root of a binary tree.
//A ZigZag path for a binary tree is defined as follow:
//Choose any node in the binary tree and a direction (right or left).
//If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
//Change the direction from right to left or from left to right.
//Repeat the second and third steps until you can't move in the tree.
//Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).
//Return the longest ZigZag path contained in that tree.


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
var longestZigZag = function(root) {
    let dfs = function(node, isLeft){
        if(node == null){
            return 0;
        }
        let left = dfs(node.left, true);
        let right = dfs(node.right, false);
        let max = Math.max(left, right);
        if(isLeft){
            max = Math.max(max, right + 1);
        }else{
            max = Math.max(max, left + 1);
        }
        return max;
    }
    return dfs(root, true);
    
};

    