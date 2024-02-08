/**https://leetcode.com/problems/binary-tree-preorder-traversal/ */
//Given the root of a binary tree, return the preorder traversal of its nodes' values.


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
 * @return {number[]}
 */
var preorderTraversal = function(root) {
    let result = [];
    let stack = [];
    let current = root;
    while(current != null || stack.length > 0){
        while(current != null){
            result.push(current.val);
            stack.push(current);
            current = current.left;
        }
        current = stack.pop();
        current = current.right;
    }
    return result;
    
};

    