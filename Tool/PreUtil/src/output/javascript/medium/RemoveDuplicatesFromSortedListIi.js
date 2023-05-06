/**https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/ */
//Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.


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
    let dummy = new ListNode(0);
    dummy.next = head;
    let current = dummy;
    while(current.next != null && current.next.next != null){
        if(current.next.val == current.next.next.val){
            let val = current.next.val;
            while(current.next != null && current.next.val == val){
                current.next = current.next.next;
            }
        }else{
            current = current.next;
        }
    }
    return dummy.next;
    
};

    