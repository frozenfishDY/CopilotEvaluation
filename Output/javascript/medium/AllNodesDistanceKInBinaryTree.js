/**https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/ */
//Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.
//You can return the answer in any order.


/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode} target
 * @param {number} k
 * @return {number[]}
 */
var distanceK = function(root, target, k) {
    let map = {};
    let result = [];
    let queue = [];
    let visited = new Set();
    queue.push(root);
    visited.add(root);
    while(queue.length > 0){
        let node = queue.shift();
        if(node.left != null){
            map[node.left.val] = node;
            queue.push(node.left);
            visited.add(node.left);
        }
        if(node.right != null){
            map[node.right.val] = node;
            queue.push(node.right);
            visited.add(node.right);
        }
    }
    queue.push(target);
    visited.add(target);
    let level = 0;
    while(queue.length > 0){
        let size = queue.length;
        for(let i = 0; i < size; i++){
            let node = queue.shift();
            if(level == k){
                result.push(node.val);
            }
            if(node.left != null && !visited.has(node.left)){
                queue.push(node.left);
                visited.add(node.left);
            }
            if(node.right != null && !visited.has(node.right)){
                queue.push(node.right);
                visited.add(node.right);
            }
            if(map[node.val] != null && !visited.has(map[node.val])){
                queue.push(map[node.val]);
                visited.add(map[node.val]);
            }
        }
        level++;
    }
    return result;
    
};

    