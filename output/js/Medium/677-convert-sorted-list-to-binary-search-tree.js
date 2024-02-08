/**https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/ */
//Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height-balanced binary search tree.


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
 * @return {TreeNode}
 */
var sortedListToBST = function(head) {
    if(head == null){
        return null;
    }
    let current = head;
    let count = 0;
    while(current != null){
        current = current.next;
        count++;
    }
    return sortedListToBSTHelper(head, 0, count - 1);
    
    
};

    