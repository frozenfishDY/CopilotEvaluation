/**https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/ */
//Given the root of a binary tree, the depth of each node is the shortest distance to the root.
//Return the smallest subtree such that it contains all the deepest nodes in the original tree.
//A node is called the deepest if it has the largest depth possible among any node in the entire tree.
//The subtree of a node is a tree consisting of that node, plus the set of all descendants of that node.


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
 * @return {TreeNode}
 */
var subtreeWithAllDeepest = function(root) {
    let map = {};
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
    queue.push(root);
    visited.add(root);
    let result = root;
    while(queue.length > 0){
        let size = queue.length;
        for(let i = 0; i < size; i++){
            let node = queue.shift();
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
        if(queue.length > 0){
            result = queue[0];
        }
    }
    return result;
    
};

    