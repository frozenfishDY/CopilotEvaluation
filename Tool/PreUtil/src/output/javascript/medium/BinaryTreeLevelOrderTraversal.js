/**https://leetcode.com/problems/binary-tree-level-order-traversal/ */
//Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).


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
 * @return {number[][]}
 */
var levelOrder = function(root) {
    let result = [];
    if(root == null){
        return result;
    }
    let queue = [];
    queue.push(root);
    while(queue.length != 0){
        let currentLevel = [];
        let currentLevelSize = queue.length;
        for(let i = 0; i < currentLevelSize; i++){
            let current = queue.shift();
            currentLevel.push(current.val);
            if(current.left != null){
                queue.push(current.left);
            }
            if(current.right != null){
                queue.push(current.right);
            }
        }
        result.push(currentLevel);
    }
    return result;
    
};

    