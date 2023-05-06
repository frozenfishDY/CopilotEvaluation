/**https://leetcode.com/problems/next-greater-node-in-linked-list/ */
//You are given the head of a linked list with n nodes.
//For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.
//Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater node, set answer[i] = 0.


/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {number[]}
 */
var nextLargerNodes = function(head) {
    let result = [];
    let stack = [];
    let index = 0;
    while(head != null){
        while(stack.length > 0 && stack[stack.length - 1][0] < head.val){
            result[stack.pop()[1]] = head.val;
        }
        stack.push([head.val, index]);
        index++;
        head = head.next;
    }
    while(stack.length > 0){
        result[stack.pop()[1]] = 0;
    }
    return result;
    
};

    