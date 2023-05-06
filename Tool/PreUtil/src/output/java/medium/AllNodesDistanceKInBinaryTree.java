/**https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/ */
//Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.
//You can return the answer in any order.


/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class AllNodesDistanceKInBinaryTree {
    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        Map<TreeNode, TreeNode> parent = new HashMap<>();
        dfs(root, null, parent);
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(null);
        queue.offer(target);
        Set<TreeNode> seen = new HashSet<>();
        seen.add(target);
        seen.add(null);
        int dist = 0;
        while(!queue.isEmpty()){
            TreeNode node = queue.poll();
            if(node == null){
                if(dist == k){
                    List<Integer> res = new ArrayList<>();
                    for(TreeNode n : queue){
                        res.add(n.val);
                    }
                    return res;
                }
                queue.offer(null);
                dist++;
            }else{
                if(!seen.contains(node.left)){
                    seen.add(node.left);
                    queue.offer(node.left);
                }
                if(!seen.contains(node.right)){
                    seen.add(node.right);
                    queue.offer(node.right);
                }
                TreeNode par = parent.get(node);
                if(!seen.contains(par)){
                    seen.add(par);
                    queue.offer(par);
                }
            }
        }
        return new ArrayList<>();
        
        
    }
}

    