/**https://leetcode.com/problems/insertion-sort-list/ */
//Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.
//The steps of the insertion sort algorithm:
//Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
//At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
//It repeats until no input elements remain.
//The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains only the first element in the list. One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.


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
var insertionSortList = function(head) {
    if(head == null){
        return null;
    }
    let dummy = new ListNode(0);
    dummy.next = head;
    let current = head;
    while(current != null && current.next != null){
        if(current.val <= current.next.val){
            current = current.next;
        }else{
            let prev = dummy;
            while(prev.next.val < current.next.val){
                prev = prev.next;
            }
            let temp = current.next;
            current.next = temp.next;
            temp.next = prev.next;
            prev.next = temp;
        }
    }
    return dummy.next;
    
};

    