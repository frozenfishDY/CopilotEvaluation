/**https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/ */
//Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes. More formally, the property root.val = min(root.left.val, root.right.val) always holds.
//Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.
//If no such second minimum value exists, output -1 instead.


/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var findSecondMinimumValue = function(root) {
    let min = root.val;
    let result = -1;
    let queue = [root];
    while(queue.length > 0){
        let node = queue.shift();
        if(node.val > min){
            if(result == -1){
                result = node.val;
            }else{
                result = Math.min(result, node.val);
            }
        }
        if(node.left != null){
            queue.push(node.left);
        }
        if(node.right != null){
            queue.push(node.right);
        }
    }
    return result;
    
};

    