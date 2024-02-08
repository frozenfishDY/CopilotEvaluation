/**https://leetcode.com/problems/reverse-nodes-in-k-group/ */
//Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
//k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
//You may not alter the values in the list's nodes, only nodes themselves may be changed.


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
var reverseKGroup = function(head, k) {
    let arr = [];
    let node = head;
    while (node) {
        arr.push(node.val);
        node = node.next;
    }
    let len = arr.length;
    let res = [];
    for (let i = 0; i < len; i += k) {
        let temp = arr.slice(i, i + k);
        if (temp.length == k) {
            temp.reverse();
        }
        res = res.concat(temp);
    }
    let headNode = new ListNode();
    let curNode = headNode;
    for (let i = 0; i < res.length; i++) {
        curNode.next = new ListNode(res[i]);
        curNode = curNode.next;
    }
    return headNode.next;
    
};

    