/**https://leetcode.com/problems/binary-tree-pruning/ */
//Given the root of a binary tree, return the same tree where every subtree (of the given tree) not containing a 1 has been removed.
//A subtree of a node node is node plus every node that is a descendant of node.


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
var pruneTree = function(root) {
    if(root == null){
        return null;
    }
    root.left = pruneTree(root.left);
    root.right = pruneTree(root.right);
    if(root.left == null && root.right == null && root.val == 0){
        return null;
    }
    return root;
    
};

    