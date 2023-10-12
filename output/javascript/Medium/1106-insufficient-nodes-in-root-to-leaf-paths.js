/**https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/ */
//Given the root of a binary tree and an integer limit, delete all insufficient nodes in the tree simultaneously, and return the root of the resulting binary tree.
//A node is insufficient if every root to leaf path intersecting this node has a sum strictly less than limit.
//A leaf is a node with no children.
// 
//Example 1:
//Input: root = [1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14], limit = 1
//Output: [1,2,3,4,null,null,7,8,9,null,14]
//Example 2:
//Input: root = [5,4,8,11,null,17,4,7,1,null,null,5,3], limit = 22
//Output: [5,4,8,11,null,17,4,7,null,null,null,5]
//Example 3:
//Input: root = [1,2,-3,-5,null,4,null], limit = -1
//Output: [1,null,-3,4]
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 5000].
//	-105 <= Node.val <= 105
//	-109 <= limit <= 109
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
 * @param {number} limit
 * @return {TreeNode}
 */
var sufficientSubset = function(root, limit) {
    const removeInsufficientNodes = (node, sum) => {
        if (!node) {
            return null;
        }
        sum += node.val;
        if (!node.left && !node.right) {
            return sum < limit ? null : node;
        }
        node.left = removeInsufficientNodes(node.left, sum);
        node.right = removeInsufficientNodes(node.right, sum);
        return node.left || node.right ? node : null;
    }
    return removeInsufficientNodes(root, 0);
};