/**https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree/ */
//You are given the root of a binary search tree and an array queries of size n consisting of positive integers.
//Find a 2D array answer of size n where answer[i] = [mini, maxi]:
//mini is the largest value in the tree that is smaller than or equal to queries[i]. If a such value does not exist, add -1 instead.
//maxi is the smallest value in the tree that is greater than or equal to queries[i]. If a such value does not exist, add -1 instead.
//Return the array answer.


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
 * @param {number[]} queries
 * @return {number[][]}
 */
var closestNodes = function(root, queries) {
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
    let result = [];
    for (let i = 0; i < queries.length; i++) {
        let query = queries[i];
        let min = -1;
        let max = -1;
        let left = 0;
        let right = arr.length - 1;
        while (left <= right) {
            let mid = Math.floor((left + right) / 2);
            if (arr[mid] === query) {
                min = arr[mid];
                max = arr[mid];
                break;
            } else if (arr[mid] < query) {
                min = arr[mid];
                left = mid + 1;
            } else {
                max = arr[mid];
                right = mid - 1;
            }
        }
        result.push([min, max]);
    }
    return result;
    
};

    