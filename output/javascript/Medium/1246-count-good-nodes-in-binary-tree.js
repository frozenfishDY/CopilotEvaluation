/**https://leetcode.com/problems/count-good-nodes-in-binary-tree/ */
//Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X._x000D_
//_x000D_
//Return the number of good nodes in the binary tree._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//_x000D_
//_x000D_
//Input: root = [3,1,4,3,null,1,5]_x000D_
//Output: 4_x000D_
//Explanation: Nodes in blue are good._x000D_
//Root Node (3) is always a good node._x000D_
//Node 4 -> (3,4) is the maximum value in the path starting from the root._x000D_
//Node 5 -> (3,4,5) is the maximum value in the path_x000D_
//Node 3 -> (3,1,3) is the maximum value in the path._x000D_
//_x000D_
//Example 2:_x000D_
//_x000D_
//_x000D_
//_x000D_
//_x000D_
//Input: root = [3,3,null,4,2]_x000D_
//Output: 3_x000D_
//Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it._x000D_
//_x000D_
//Example 3:_x000D_
//_x000D_
//_x000D_
//Input: root = [1]_x000D_
//Output: 1_x000D_
//Explanation: Root is considered as good._x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	The number of nodes in the binary tree is in the range [1, 10^5]._x000D_
//	Each node's value is between [-10^4, 10^4]._x000D_
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
var goodNodes = function(root) {
    
};