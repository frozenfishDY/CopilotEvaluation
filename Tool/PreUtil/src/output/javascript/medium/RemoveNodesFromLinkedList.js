/**https://leetcode.com/problems/remove-nodes-from-linked-list/ */
//You are given the head of a linked list.
//Remove every node which has a node with a strictly greater value anywhere to the right side of it.
//Return the head of the modified linked list.


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
var removeNodes = function(head) {
    let result = new ListNode(0);
    let temp = result;
    let max = 0;
    while(head != null){
        if(head.val >= max){
            max = head.val;
            temp.next = head;
            temp = temp.next;
        }
        head = head.next;
    }
    temp.next = null;
    return result.next;
    
};

    