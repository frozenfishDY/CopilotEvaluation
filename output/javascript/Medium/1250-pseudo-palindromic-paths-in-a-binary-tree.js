/**https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/ */
//Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be pseudo-palindromic if at least one permutation of the node values in the path is a palindrome.
//Return the number of pseudo-palindromic paths going from the root node to leaf nodes.
// 
//Example 1:
//Input: root = [2,3,1,3,1,null,1]
//Output: 2 
//Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the red path [2,3,3], the green path [2,1,1], and the path [2,3,1]. Among these paths only red path and green path are pseudo-palindromic paths since the red path [2,3,3] can be rearranged in [3,2,3] (palindrome) and the green path [2,1,1] can be rearranged in [1,2,1] (palindrome).
//Example 2:
//Input: root = [2,1,1,1,3,null,null,null,null,null,1]
//Output: 1 
//Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the green path [2,1,1], the path [2,1,3,1], and the path [2,1]. Among these paths only the green path is pseudo-palindromic since [2,1,1] can be rearranged in [1,2,1] (palindrome).
//Example 3:
//Input: root = [9]
//Output: 1
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 105].
//	1 <= Node.val <= 9
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
var pseudoPalindromicPaths  = function(root) {
    let result = 0;
    let arr = new Array(9).fill(0);
    function dfs(node) {
        arr[node.val - 1]++;
        if (!node.left && !node.right) {
            let odd = 0;
            for (let i = 0; i < arr.length; i++) {
                if (arr[i] % 2 === 1) {
                    odd++;
                }
            }
            if (odd <= 1) {
                result++;
            }
        }
        if (node.left) {
            dfs(node.left);
        }
        if (node.right) {
            dfs(node.right);
        }
        arr[node.val - 1]--;
    }
    dfs(root);
    return result;
};