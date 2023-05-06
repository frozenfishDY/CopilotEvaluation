/**https://leetcode.com/problems/binary-tree-right-side-view/ */
//Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.


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
 * @return {number[]}
 */
var rightSideView = function(root) {
    let result = [];
    if(root == null){
        return result;
    }
    let queue = [];
    queue.push(root);
    while(queue.length != 0){
        let currentLevelSize = queue.length;
        for(let i = 0; i < currentLevelSize; i++){
            let current = queue.shift();
            if(i == currentLevelSize - 1){
                result.push(current.val);
            }
            if(current.left != null){
                queue.push(current.left);
            }
            if(current.right != null){
                queue.push(current.right);
            }
        }
    }
    return result;
    
};

    