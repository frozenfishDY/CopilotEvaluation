/**https://leetcode.com/problems/recover-binary-search-tree/ */
//You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.


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
 * @return {void} Do not return anything, modify root in-place instead.
 */
var recoverTree = function(root) {
    let first = null;
    let second = null;
    let prev = null;
    let current = root;
    let stack = [];
    while(current != null || stack.length != 0){
        while(current != null){
            stack.push(current);
            current = current.left;
        }
        current = stack.pop();
        if(prev != null && prev.val > current.val){
            if(first == null){
                first = prev;
            }
            second = current;
        }
        prev = current;
        current = current.right;
    }
    let temp = first.val;
    first.val = second.val;
    second.val = temp;
    
};

    