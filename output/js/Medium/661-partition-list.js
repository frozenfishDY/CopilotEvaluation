/**https://leetcode.com/problems/partition-list/ */
//Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
//You should preserve the original relative order of the nodes in each of the two partitions.


/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} x
 * @return {ListNode}
 */
var partition = function(head, x) {
    let dummy = new ListNode(0);
    dummy.next = head;
    let current = dummy;
    let prev = dummy;
    while(current.next != null){
        if(current.next.val < x){
            if(current != prev){
                let temp = current.next;
                current.next = current.next.next;
                temp.next = prev.next;
                prev.next = temp;
                prev = prev.next;
            }else{
                current = current.next;
                prev = prev.next;
            }
        }else{
            current = current.next;
        }
    }
    return dummy.next;
    
};

    