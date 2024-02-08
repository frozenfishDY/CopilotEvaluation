/**https://leetcode.com/problems/smallest-string-starting-from-leaf/ */
//You are given the root of a binary tree where each node has a value in the range [0, 25] representing the letters 'a' to 'z'.
//Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.
//As a reminder, any shorter prefix of a string is lexicographically smaller.
//For example, "ab" is lexicographically smaller than "aba".
//A leaf of a node is a node that has no children.


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
 * @return {string}
 */
var smallestFromLeaf = function(root) {
    let result = [];
    function dfs(root, str){
        if(root == null){
            return;
        }
        str = String.fromCharCode(97 + root.val) + str;
        if(root.left == null && root.right == null){
            result.push(str);
            return;
        }
        dfs(root.left, str);
        dfs(root.right, str);
    }
    dfs(root, "");
    result.sort();
    return result[0];
    
};

    