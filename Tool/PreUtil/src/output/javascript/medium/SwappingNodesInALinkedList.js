/**https://leetcode.com/problems/swapping-nodes-in-a-linked-list/ */
//You are given the head of a linked list, and an integer k.
//Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).


/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */
var swapNodes = function(head, k) {
    let n = 0;
    let node = head;
    while (node != null) {
        n++;
        node = node.next;
    }
    let first = head;
    for (let i = 1; i < k; i++) {
        first = first.next;
    }
    let second = head;
    for (let i = 1; i < n - k + 1; i++) {
        second = second.next;
    }
    let temp = first.val;
    first.val = second.val;
    second.val = temp;
    return head;
    
};

    