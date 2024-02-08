/**https://leetcode.com/problems/insertion-sort-list/ */
//Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.
//The steps of the insertion sort algorithm:
//Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
//At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
//It repeats until no input elements remain.
//The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains only the first element in the list. One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.


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
class InsertionSortList {
    public ListNode insertionSortList(ListNode head) {
        if(head == null || head.next == null){
            return head;
        }
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode cur = head;
        while(cur != null && cur.next != null){
            if(cur.val <= cur.next.val){
                cur = cur.next;
            }else{
                ListNode temp = cur.next;
                cur.next = temp.next;
                ListNode pre = dummy;
                while(pre.next.val < temp.val){
                    pre = pre.next;
                }
                temp.next = pre.next;
                pre.next = temp;
            }
        }
        return dummy.next;
        
        
    }
}

    