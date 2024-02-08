/**https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/ */
//Given the root of a binary tree, return the number of nodes where the value of the node is equal to the average of the values in its subtree.
//Note:
//The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
//A subtree of root is a tree consisting of root and all of its descendants.


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
var averageOfSubtree = function(root) {
    let result = 0;
    let stack = [];
    let node = root;
    while (node || stack.length) {
        while (node) {
            stack.push(node);
            node = node.left;
        }
        node = stack.pop();
        if (node.val >= root.val) {
            result++;
        }
        node = node.right;
    }
    return result;
    
};

    