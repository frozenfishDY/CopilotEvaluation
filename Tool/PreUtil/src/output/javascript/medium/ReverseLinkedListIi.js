/**https://leetcode.com/problems/reverse-linked-list-ii/ */
//Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.


/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} left
 * @param {number} right
 * @return {ListNode}
 */
var reverseBetween = function(head, left, right) {
    let dummy = new ListNode(0);
    dummy.next = head;
    let current = dummy;
    let prev = dummy;
    let count = 1;
    while(current.next != null){
        if(count == left){
            let temp = current.next;
            current.next = current.next.next;
            temp.next = prev.next;
            prev.next = temp;
            prev = prev.next;
            count++;
        }else if(count > left && count < right){
            let temp = current.next;
            current.next = current.next.next;
            temp.next = prev.next;
            prev.next = temp;
            count++;
        }else if(count == right){
            let temp = current.next;
            current.next = current.next.next;
            temp.next = prev.next;
            prev.next = temp;
            count++;
        }else{
            current = current.next;
            prev = prev.next;
            count++;
        }
    }
    return dummy.next;
    
};

    