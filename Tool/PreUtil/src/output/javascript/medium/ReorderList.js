/**https://leetcode.com/problems/reorder-list/ */
//You are given the head of a singly linked-list. The list can be represented as:
//L0 �� L1 �� �� �� Ln - 1 �� Ln
//Reorder the list to be on the following form:
//L0 �� Ln �� L1 �� Ln - 1 �� L2 �� Ln - 2 �� ��
//You may not modify the values in the list's nodes. Only nodes themselves may be changed.


/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {void} Do not return anything, modify head in-place instead.
 */
var reorderList = function(head) {
    if(head == null){
        return;
    }
    let slow = head;
    let fast = head;
    while(fast != null && fast.next != null){
        slow = slow.next;
        fast = fast.next.next;
    }
    let prev = null;
    let current = slow;
    while(current != null){
        let next = current.next;
        current.next = prev;
        prev = current;
        current = next;
    }
    let first = head;
    let second = prev;
    while(second.next != null){
        let firstNext = first.next;
        let secondNext = second.next;
        first.next = second;
        second.next = firstNext;
        first = firstNext;
        second = secondNext;
    }
    
};

    