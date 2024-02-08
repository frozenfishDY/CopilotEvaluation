/**https://leetcode.com/problems/average-of-levels-in-binary-tree/ */
//Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. Answers within 10-5 of the actual answer will be accepted.


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
var averageOfLevels = function(root) {
    let result = [];
    let queue = [root];
    while(queue.length > 0){
        let sum = 0;
        let count = 0;
        let newQueue = [];
        for(let node of queue){
            sum += node.val;
            count++;
            if(node.left != null){
                newQueue.push(node.left);
            }
            if(node.right != null){
                newQueue.push(node.right);
            }
        }
        result.push(sum / count);
        queue = newQueue;
    }
    return result;
    
};

    