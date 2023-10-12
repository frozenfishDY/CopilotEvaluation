/**https://leetcode.com/problems/delete-nodes-and-return-forest/ */
//Given the root of a binary tree, each node in the tree has a distinct value.
//After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).
//Return the roots of the trees in the remaining forest. You may return the result in any order.
// 
//Example 1:
//Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
//Output: [[1,2,null,4],[6],[7]]
//Example 2:
//Input: root = [1,2,4,null,3], to_delete = [3]
//Output: [[1,2,4]]
// 
//Constraints:
//	The number of nodes in the given tree is at most 1000.
//	Each node has a distinct value between 1 and 1000.
//	to_delete.length <= 1000
//	to_delete contains distinct values between 1 and 1000.
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
    public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
        // 1. create a set to store all the nodes to be deleted
		// 2. create a list to store all the roots
		// 3. create a dfs function to recursively delete the nodes
		// 3.1 if the current node is null, return null
		// 3.2 if the current node's value is in the set, return null
		// 3.3 if the current node's value is not in the set, return the current node
		// 3.4 if the current node's value is in the set, delete the left child and the right child
		// 3.5 if the left child is not null and the left child's value is not in the set, add the left child to the list
		// 3.6 if the right child is not null and the right child's value is not in the set, add the right child to the list
		// 3.7 return the current node
		// 4. call the dfs function
		// 5. return the list
        Set<Integer> set = new HashSet<>();
        for(int i: to_delete) {
            set.add(i);
        }
        List<TreeNode> list = new ArrayList<>();
        dfs(root, set, list);
        if(!set.contains(root.val)) {
            list.add(root);
        }
        return list;
    }
    private TreeNode dfs(TreeNode root, Set<Integer> set, List<TreeNode> list) {
        if(root == null) {
            return null;
        }
        if(set.contains(root.val)) {
            root.left = dfs(root.left, set, list);
            root.right = dfs(root.right, set, list);
            return null;
        }
        root.left = dfs(root.left, set, list);
        root.right = dfs(root.right, set, list);
        return root;
    }
}
    
