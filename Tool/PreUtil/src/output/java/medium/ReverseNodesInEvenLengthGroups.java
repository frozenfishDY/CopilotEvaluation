/**https://leetcode.com/problems/reverse-nodes-in-even-length-groups/ */
//You are given the head of a linked list.
//The nodes in the linked list are sequentially assigned to non-empty groups whose lengths form the sequence of the natural numbers (1, 2, 3, 4, ...). The length of a group is the number of nodes assigned to it. In other words,
//The 1st node is assigned to the first group.
//The 2nd and the 3rd nodes are assigned to the second group.
//The 4th, 5th, and 6th nodes are assigned to the third group, and so on.
//Note that the length of the last group may be less than or equal to 1 + the length of the second to last group.
//Reverse the nodes in each group with an even length, and return the head of the modified linked list.


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
class ReverseNodesInEvenLengthGroups {
    public ListNode reverseEvenLengthGroups(ListNode head) {
        ListNode dummy = new ListNode(0, head);
        ListNode prev = dummy;
        ListNode curr = head;
        int count = 1;
        while(curr != null){
            if(count % 2 == 0){
                ListNode next = curr.next;
                curr.next = prev;
                prev = curr;
                curr = next;
            }else{
                ListNode next = curr.next;
                curr.next = prev;
                prev = curr;
                curr = next;
                count++;
            }
        }
        return prev;
        
    }
}
     
    