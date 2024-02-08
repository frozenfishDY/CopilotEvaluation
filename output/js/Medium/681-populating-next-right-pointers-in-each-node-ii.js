/**https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/ */
//Given a binary tree
//struct Node {
//  int val;
//  Node *left;
//  Node *right;
//  Node *next;
//}
//Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
//Initially, all next pointers are set to NULL.


/**
 * // Definition for a Node.
 * function Node(val, left, right, next) {
 *    this.val = val === undefined ? null : val;
 *    this.left = left === undefined ? null : left;
 *    this.right = right === undefined ? null : right;
 *    this.next = next === undefined ? null : next;
 * };
 */

/**
 * @param {Node} root
 * @return {Node}
 */
var connect = function(root) {
    if(root == null){
        return root;
    }
    let queue = [];
    queue.push(root);
    while(queue.length != 0){
        let currentLevelSize = queue.length;
        let prev = null;
        for(let i = 0; i < currentLevelSize; i++){
            let current = queue.shift();
            if(prev != null){
                prev.next = current;
            }
            if(current.left != null){
                queue.push(current.left);
            }
            if(current.right != null){
                queue.push(current.right);
            }
            prev = current;
        }
    }
    return root;
    
};

    