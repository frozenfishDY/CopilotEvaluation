/**https://leetcode.com/problems/swapping-nodes-in-a-linked-list/ */
//You are given the head of a linked list, and an integer k.
//Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).


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
class SwappingNodesInALinkedList {
    public ListNode swapNodes(ListNode head, int k) {
        ListNode dummy = new ListNode(0, head);
        ListNode p = dummy;
        ListNode q = dummy;
        for(int i = 0; i < k; i++){
            p = p.next;
        }
        ListNode first = p;
        while(p.next != null){
            p = p.next;
            q = q.next;
        }
        ListNode second = q.next;
        int temp = first.val;
        first.val = second.val;
        second.val = temp;
        return dummy.next;
        
    }
}
     
    