/**https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/ */
//You are given the root of a binary tree and a positive integer k.
//The level sum in the tree is the sum of the values of the nodes that are on the same level.
//Return the kth largest level sum in the tree (not necessarily distinct). If there are fewer than k levels in the tree, return -1.
//Note that two nodes are on the same level if they have the same distance from the root.
// 
//Example 1:
//Input: root = [5,8,9,2,1,3,7,4,6], k = 2
//Output: 13
//Explanation: The level sums are the following:
//- Level 1: 5.
//- Level 2: 8 + 9 = 17.
//- Level 3: 2 + 1 + 3 + 7 = 13.
//- Level 4: 4 + 6 = 10.
//The 2nd largest level sum is 13.
//Example 2:
//Input: root = [1,2,null,3], k = 1
//Output: 3
//Explanation: The largest level sum is 3.
// 
//Constraints:
//	The number of nodes in the tree is n.
//	2 <= n <= 105
//	1 <= Node.val <= 106
//	1 <= k <= n
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
 * @param {number} k
 * @return {number}
 */
var kthLargestLevelSum = function(root, k) { 
    let queue = [root];
    let level = 0;
    let map = new Map();
    while (queue.length > 0) {
        let len = queue.length;
        let sum = 0;
        for (let i = 0; i < len; i++) {
            let node = queue.shift();
            sum += node.val;
            if (node.left) queue.push(node.left);
            if (node.right) queue.push(node.right);
        }
        map.set(level, sum);
        level++;
    }
    let arr = [...map.values()];
    arr.sort((a,b) => b-a);
    return arr[k-1];
};