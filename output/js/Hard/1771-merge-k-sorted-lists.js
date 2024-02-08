/**https://leetcode.com/problems/merge-k-sorted-lists/ */
//You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
//Merge all the linked-lists into one sorted linked-list and return it.


/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode[]} lists
 * @return {ListNode}
 */
var mergeKLists = function(lists) {
    let arr = [];
    for (let i = 0; i < lists.length; i++) {
        let node = lists[i];
        while (node) {
            arr.push(node.val);
            node = node.next;
        }
    }
    arr.sort((a, b) => a - b);
    let head = new ListNode();
    let node = head;
    for (let i = 0; i < arr.length; i++) {
        node.next = new ListNode(arr[i]);
        node = node.next;
    }
    return head.next;
    
};

    