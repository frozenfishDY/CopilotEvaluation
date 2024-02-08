/**https://leetcode.com/problems/remove-nodes-from-linked-list/ */
//You are given the head of a linked list.
//Remove every node which has a node with a strictly greater value anywhere to the right side of it.
//Return the head of the modified linked list.


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
class RemoveNodesFromLinkedList {
    public ListNode removeNodes(ListNode head) {
        if(head == null){
            return null;
        }
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode prev = dummy;
        ListNode curr = head;
        while(curr != null){
            while(curr.next != null && curr.val >= curr.next.val){
                curr = curr.next;
            }
            if(prev.next == curr){
                prev = prev.next;
            }else{
                prev.next = curr.next;
            }
            curr = curr.next;
        }
        return dummy.next;
        
        
    }
}

    