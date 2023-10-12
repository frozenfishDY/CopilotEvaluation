/**https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/ */
//Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
//Return the smallest level x such that the sum of all the values of nodes at level x is maximal.
// 
//Example 1:
//Input: root = [1,7,0,7,-8,null,null]
//Output: 2
//Explanation: 
//Level 1 sum = 1.
//Level 2 sum = 7 + 0 = 7.
//Level 3 sum = 7 + -8 = -1.
//So we return the level with the maximum sum which is level 2.
//Example 2:
//Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
//Output: 2
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 104].
//	-105 <= Node.val <= 105
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
var maxLevelSum = function(root) {
    var ans = 1;
	var maxSum = Number.MIN_SAFE_INTEGER;
	var queue = [];
	queue.push(root);
	for (var level = 1; queue.length > 0; level++) {
		var sum = 0;
		for (var i = queue.length - 1; i >= 0; i--) {
			var node = queue.shift();
			sum += node.val;
			if (node.left != null) {
				queue.push(node.left);
			}
			if (node.right != null) {
				queue.push(node.right);
			}
		}
		if (sum > maxSum) {
			maxSum = sum;
			ans = level;
		}
	}
	return ans;
};