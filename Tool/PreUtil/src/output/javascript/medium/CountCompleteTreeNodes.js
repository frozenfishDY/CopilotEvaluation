/**https://leetcode.com/problems/count-complete-tree-nodes/ */
//Given the root of a complete binary tree, return the number of the nodes in the tree.
//According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
//Design an algorithm that runs in less than O(n) time complexity.


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
var countNodes = function(root) {
    if(root == null){
        return 0;
    }
    let leftHeight = 0;
    let rightHeight = 0;
    let left = root;
    let right = root;
    while(left != null){
        left = left.left;
        leftHeight++;
    }
    while(right != null){
        right = right.right;
        rightHeight++;
    }
    if(leftHeight == rightHeight){
        return Math.pow(2, leftHeight) - 1;
    }
    return 1 + countNodes(root.left) + countNodes(root.right);
    
};

    