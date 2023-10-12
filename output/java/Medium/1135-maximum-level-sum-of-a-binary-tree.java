/**https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/ */
//Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
//Return the smallest level x such that the sum of all the values of nodes at level x is maximal.
// 
//Example 1:
//Input: root = [1,7,0,7,-8,null,null]
//Output: 2
//Explanation: 
//Level 1 sum = 1.
//Level 2 sum = 7 + 0 = 7.
//Level 3 sum = 7 + -8 = -1.
//So we return the level with the maximum sum which is level 2.
//Example 2:
//Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
//Output: 2
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 104].
//	-105 <= Node.val <= 105
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int maxLevelSum(TreeNode root) {
        // 1. create a variable to store the level with the maximum sum
		// 2. create a variable to store the maximum sum
		// 3. create a queue to store all the nodes
		// 4. create a while loop to iterate through the queue
		// 4.1 create a variable to store the size of the queue
		// 4.2 create a variable to store the sum
		// 4.3 create a for loop to iterate through the queue
		// 4.3.1 get the current node
		// 4.3.2 add the current node's value to the sum
		// 4.3.3 if the current node's left child is not null, add the current node's left child to the queue
		// 4.3.4 if the current node's right child is not null, add the current node's right child to the queue
		// 4.4 update the level with the maximum sum and the maximum sum
		// 5. return the level with the maximum sum
        int level = 1;
        int max = Integer.MIN_VALUE;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        while(!queue.isEmpty()) {
            int size = queue.size();
            int sum = 0;
            for(int i = 0; i < size; i++) {
                TreeNode curr = queue.poll();
                sum += curr.val;
                if(curr.left != null) {
                    queue.offer(curr.left);
                }
                if(curr.right != null) {
                    queue.offer(curr.right);
                }
            }
            if(sum > max) {
                max = sum;
                level = queue.size();
            }
        }
        return level;
    }
}