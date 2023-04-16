/**https://leetcode.com/problems/remove-linked-list-elements/ */
//Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.


/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} val
 * @return {ListNode}
 */
var removeElements = function(head, val) {
    let current = head;
    let prev = null;
    while(current != null){
        if(current.val == val){
            if(prev == null){
                head = current.next;
            }else{
                prev.next = current.next;
            }
        }else{
            prev = current;
        }
        current = current.next;
    }
    return head;
    
};

    