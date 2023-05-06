/**https://leetcode.com/problems/all-elements-in-two-binary-search-trees/ */
//Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.


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
class AllElementsInTwoBinarySearchTrees {
    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        List<Integer> res = new ArrayList<>();
        Stack<TreeNode> stack1 = new Stack<>();
        Stack<TreeNode> stack2 = new Stack<>();
        TreeNode node1 = root1;
        TreeNode node2 = root2;
        while(node1 != null || !stack1.isEmpty() || node2 != null || !stack2.isEmpty()){
            while(node1 != null){
                stack1.push(node1);
                node1 = node1.left;
            }
            while(node2 != null){
                stack2.push(node2);
                node2 = node2.left;
            }
            if(stack2.isEmpty() || !stack1.isEmpty() && stack1.peek().val <= stack2.peek().val){
                node1 = stack1.pop();
                res.add(node1.val);
                node1 = node1.right;
            }else{
                node2 = stack2.pop();
                res.add(node2.val);
                node2 = node2.right;
            }
        }
        return res;
        
    }
}

    