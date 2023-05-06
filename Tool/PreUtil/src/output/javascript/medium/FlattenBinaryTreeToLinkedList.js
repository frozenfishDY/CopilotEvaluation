/**https://leetcode.com/problems/flatten-binary-tree-to-linked-list/ */
//Given the root of a binary tree, flatten the tree into a "linked list":
//The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
//The "linked list" should be in the same order as a pre-order traversal of the binary tree.


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
var flatten = function(root) {
    if(root == null){
        return;
    }
    let stack = [];
    stack.push(root);
    let prev = null;
    while(stack.length != 0){
        let current = stack.pop();
        if(prev != null){
            prev.left = null;
            prev.right = current;
        }
        let right = current.right;
        let left = current.left;
        if(right != null){
            stack.push(right);
        }
        if(left != null){
            stack.push(left);
        }
        prev = current;
    }
    
};

    