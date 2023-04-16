/**https://leetcode.com/problems/linked-list-in-binary-tree/ */
//Given a binary tree root and a linked list with head as the first node. 
//Return True if all the elements in the linked list starting from the head correspond to some downward path connected in the binary tree otherwise return False.
//In this context downward path means a path that starts at some node and goes downwards.


/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {ListNode} head
 * @param {TreeNode} root
 * @return {boolean}
 */
var isSubPath = function(head, root) {
    let dfs = function(node, head){
        if(head == null){
            return true;
        }
        if(node == null){
            return false;
        }
        if(node.val != head.val){
            return false;
        }
        return dfs(node.left, head.next) || dfs(node.right, head.next);
    }
    let dfs2 = function(node){
        if(node == null){
            return false;
        }
        if(node.val == head.val){
            if(dfs(node, head)){
                return true;
            }
        }
        return dfs2(node.left) || dfs2(node.right);
    }
    return dfs2(root);
    
};

    