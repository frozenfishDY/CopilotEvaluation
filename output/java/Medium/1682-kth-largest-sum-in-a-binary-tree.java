/**https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/ */
//You are given the root of a binary tree and a positive integer k.
//The level sum in the tree is the sum of the values of the nodes that are on the same level.
//Return the kth largest level sum in the tree (not necessarily distinct). If there are fewer than k levels in the tree, return -1.
//Note that two nodes are on the same level if they have the same distance from the root.
// 
//Example 1:
//Input: root = [5,8,9,2,1,3,7,4,6], k = 2
//Output: 13
//Explanation: The level sums are the following:
//- Level 1: 5.
//- Level 2: 8 + 9 = 17.
//- Level 3: 2 + 1 + 3 + 7 = 13.
//- Level 4: 4 + 6 = 10.
//The 2nd largest level sum is 13.
//Example 2:
//Input: root = [1,2,null,3], k = 1
//Output: 3
//Explanation: The largest level sum is 3.
// 
//Constraints:
//	The number of nodes in the tree is n.
//	2 <= n <= 105
//	1 <= Node.val <= 106
//	1 <= k <= n
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
    public long kthLargestLevelSum(TreeNode root, int k) {
        Map<Integer, Long> levelSums = new HashMap<>();
        dfs(root, 0, levelSums);
        PriorityQueue<Long> pq = new PriorityQueue<>();
        for (Long levelSum : levelSums.values()) {
            pq.offer(levelSum);
            if (pq.size() > k) {
                pq.poll();
            }
        }
        return pq.size() < k ? -1 : pq.poll();
    }
    private void dfs(TreeNode root, int level, Map<Integer, Long> levelSums) {
        if (root == null) {
            return;
        }
        levelSums.put(level, levelSums.getOrDefault(level, 0L) + root.val);
        dfs(root.left, level + 1, levelSums);
        dfs(root.right, level + 1, levelSums);
    }
}