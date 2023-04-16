/**https://leetcode.com/problems/remove-duplicates-from-sorted-list/ */
//Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.


/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var deleteDuplicates = function(head) {
    let current = head;
    while(current != null && current.next != null){
        if(current.val == current.next.val){
            current.next = current.next.next;
        }else{
            current = current.next;
        }
    }
    return head;
    
};

    