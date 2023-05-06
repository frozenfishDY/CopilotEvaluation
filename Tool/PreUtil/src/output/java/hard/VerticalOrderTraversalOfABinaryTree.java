/**https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/ */
//Given the root of a binary tree, calculate the vertical order traversal of the binary tree.
//For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).
//The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.
//Return the vertical order traversal of the binary tree.


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
class VerticalOrderTraversalOfABinaryTree {
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        if (root == null) {
            return result;
        }
        Map<Integer, List<Integer>> map = new TreeMap<>();
        Queue<TreeNode> queue = new LinkedList<>();
        Queue<Integer> cols = new LinkedList<>();
        queue.offer(root);
        cols.offer(0);
        while (!queue.isEmpty()) {
            int size = queue.size();
            Map<Integer, List<Integer>> temp = new TreeMap<>();
            for (int i = 0; i < size; i++) {
                TreeNode node = queue.poll();
                int col = cols.poll();
                if (!temp.containsKey(col)) {
                    temp.put(col, new ArrayList<>());
                }
                temp.get(col).add(node.val);
                if (node.left != null) {
                    queue.offer(node.left);
                    cols.offer(col - 1);
                }
                if (node.right != null) {
                    queue.offer(node.right);
                    cols.offer(col + 1);
                }
            }
            for (int key : temp.keySet()) {
                List<Integer> list = temp.get(key);
                Collections.sort(list);
                if (!map.containsKey(key)) {
                    map.put(key, new ArrayList<>());
                }
                map.get(key).addAll(list);
            }
        }
        for (int key : map.keySet()) {
            result.add(map.get(key));
        }
        return result;
        
    }
}
     
    