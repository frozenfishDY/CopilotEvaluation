/**https://leetcode.com/problems/symmetric-tree/ */
//Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).


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
 * @return {boolean}
 */
var isSymmetric = function(root) {
    if(root == null){
        return true;
    }
    return isMirror(root.left, root.right);
    
    
};

    