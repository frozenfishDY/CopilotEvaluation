/**https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/ */
//You are given the root of a binary tree with unique values.
//In one operation, you can choose any two nodes at the same level and swap their values.
//Return the minimum number of operations needed to make the values at each level sorted in a strictly increasing order.
//The level of a node is the number of edges along the path between it and the root node.


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
var minimumOperations = function(root) {
    let arr = [];
    let stack = [];
    let node = root;
    while (node || stack.length) {
        while (node) {
            stack.push(node);
            node = node.left;
        }
        node = stack.pop();
        arr.push(node.val);
        node = node.right;
    }
    let result = 0;
    let left = 0;
    let right = arr.length - 1;
    while (left < right) {
        if (arr[left] > arr[right]) {
            result++;
            left++;
        } else {
            left++;
            right--;
        }
    }
    return result;
    
};

    