/**https://leetcode.com/problems/sum-of-left-leaves/ */
//Given the root of a binary tree, return the sum of all left leaves.
//A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.


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
var sumOfLeftLeaves = function(root) {
    if(root == null){
        return 0;
    }
    let sum = 0;
    if(root.left != null && root.left.left == null && root.left.right == null){
        sum += root.left.val;
    }
    sum += sumOfLeftLeaves(root.left);
    sum += sumOfLeftLeaves(root.right);
    return sum;
    
};

    