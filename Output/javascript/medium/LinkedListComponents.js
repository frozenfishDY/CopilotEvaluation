/**https://leetcode.com/problems/linked-list-components/ */
//You are given the head of a linked list containing unique integer values and an integer array nums that is a subset of the linked list values.
//Return the number of connected components in nums where two values are connected if they appear consecutively in the linked list.


/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number[]} nums
 * @return {number}
 */
var numComponents = function(head, nums) {
    let result = 0;
    let set = new Set();
    for(let i = 0; i < nums.length; i++){
        set.add(nums[i]);
    }
    let current = head;
    let connected = false;
    while(current != null){
        if(set.has(current.val)){
            if(!connected){
                result++;
                connected = true;
            }
        }else{
            connected = false;
        }
        current = current.next;
    }
    return result;
    
};

    