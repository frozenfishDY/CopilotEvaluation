/**https://leetcode.com/problems/binary-tree-coloring-game/ */
//Two players play a turn based game on a binary tree. We are given the root of this binary tree, and the number of nodes n in the tree. n is odd, and each node has a distinct value from 1 to n.
//Initially, the first player names a value x with 1 <= x <= n, and the second player names a value y with 1 <= y <= n and y != x. The first player colors the node with value x red, and the second player colors the node with value y blue.
//Then, the players take turns starting with the first player. In each turn, that player chooses a node of their color (red if player 1, blue if player 2) and colors an uncolored neighbor of the chosen node (either the left child, right child, or parent of the chosen node.)
//If (and only if) a player cannot choose such a node in this way, they must pass their turn. If both players pass their turn, the game ends, and the winner is the player that colored more nodes.
//You are the second player. If it is possible to choose such a y to ensure you win the game, return true. If it is not possible, return false.
// 
//Example 1:
//Input: root = [1,2,3,4,5,6,7,8,9,10,11], n = 11, x = 3
//Output: true
//Explanation: The second player can choose the node with value 2.
//Example 2:
//Input: root = [1,2,3], n = 3, x = 1
//Output: false
// 
//Constraints:
//	The number of nodes in the tree is n.
//	1 <= x <= n <= 100
//	n is odd.
//	1 <= Node.val <= n
//	All the values of the tree are unique.
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
    public boolean btreeGameWinningMove(TreeNode root, int n, int x) {
        // 1. create a variable to store the number of nodes in the left child
		// 2. create a variable to store the number of nodes in the right child
		// 3. create a variable to store the number of nodes in the parent
		// 4. create a dfs function to recursively count the number of nodes in the left child, the right child, and the parent
		// 4.1 if the current node is null, return 0
		// 4.2 if the current node is not null, get the number of nodes in the left child, the right child, and the parent
		// 4.3 if the current node's value is equal to x, update the number of nodes in the left child, the right child, and the parent
		// 4.4 return the number of nodes in the left child, the right child, and the parent
		// 5. call the dfs function
		// 6. return the number of nodes in the left child, the right child, and the parent
        int[] count = new int[3];
        dfs(root, count, x);
        int max = Math.max(count[0], Math.max(count[1], count[2]));
        return max > n/2;
    }
    private int dfs(TreeNode root, int[] count, int x) {
        if(root == null) {
            return 0;
        }
        int left = dfs(root.left, count, x);
        int right = dfs(root.right, count, x);
        int parent = 1 + left + right;
        if(root.val == x) {
            count[0] = left;
            count[1] = right;
            count[2] = parent;
        }
        return parent;
    }
}