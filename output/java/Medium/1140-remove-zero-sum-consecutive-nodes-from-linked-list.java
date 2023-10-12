/**https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/ */
//Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences._x000D_
//_x000D_
//After doing so, return the head of the final linked list.  You may return any such answer._x000D_
// 
//(Note that in the examples below, all sequences are serializations of ListNode objects.)
//Example 1:
//Input: head = [1,2,-3,3,1]
//Output: [3,1]
//Note: The answer [1,2,1] would also be accepted.
//Example 2:
//Input: head = [1,2,3,-3,4]
//Output: [1,2,4]
//Example 3:
//Input: head = [1,2,3,-3,-2]
//Output: [1]
// 
//Constraints:
//	The given linked list will contain between 1 and 1000 nodes.
//	Each node in the linked list has -1000 <= node.val <= 1000.
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
class Solution {
    public ListNode removeZeroSumSublists(ListNode head) {
        // 1. create a dummy node
		// 2. create a map to store the sum and the node
		// 3. create a variable to store the sum
		// 4. iterate the linked list
		// 4.1 add the current node's value to the sum
		// 4.2 if the map contains the sum, get the node from the map and set the next node to the current node's next node
		// 4.3 if the map does not contain the sum, add the sum and the current node to the map
		// 5. return the dummy node's next node
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        Map<Integer, ListNode> map = new HashMap<>();
        int sum = 0;
        for(ListNode cur = dummy; cur != null; cur = cur.next) {
            sum += cur.val;
            if(map.containsKey(sum)) {
                cur.next = map.get(sum).next;
            } else {
                map.put(sum, cur);
            }
        }
        return dummy.next;
    }
}