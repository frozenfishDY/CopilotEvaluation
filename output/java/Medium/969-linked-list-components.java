/**https://leetcode.com/problems/linked-list-components/ */
//You are given the head of a linked list containing unique integer values and an integer array nums that is a subset of the linked list values.
//Return the number of connected components in nums where two values are connected if they appear consecutively in the linked list.


/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class LinkedListComponents {
    public int numComponents(ListNode head, int[] nums) {
        Set<Integer> set = new HashSet<>();
        for(int num : nums){
            set.add(num);
        }
        int res = 0;
        ListNode cur = head;
        while(cur != null){
            if(set.contains(cur.val) && (cur.next == null || !set.contains(cur.next.val))){
                res++;
            }
            cur = cur.next;
        }
        return res;
        
    }
}

    