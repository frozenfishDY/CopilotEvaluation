/**https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/ */
//Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).


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
var zigzagLevelOrder = function(root) {
    let result = [];
    if(root == null){
        return result;
    }
    let queue = [];
    queue.push(root);
    let isLeftToRight = true;
    while(queue.length != 0){
        let currentLevel = [];
        let currentLevelSize = queue.length;
        for(let i = 0; i < currentLevelSize; i++){
            let current = queue.shift();
            if(isLeftToRight){
                currentLevel.push(current.val);
            }else{
                currentLevel.unshift(current.val);
            }
            if(current.left != null){
                queue.push(current.left);
            }
            if(current.right != null){
                queue.push(current.right);
            }
        }
        result.push(currentLevel);
        isLeftToRight = !isLeftToRight;
    }
    return result;
    
};

    