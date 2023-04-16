/**https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/ */
//Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.
//If there exist multiple answers, you can return any of them.


/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[]} preorder
 * @param {number[]} postorder
 * @return {TreeNode}
 */
var constructFromPrePost = function(preorder, postorder) {
    if(preorder.length == 0 || postorder.length == 0){
        return null;
    }
    let root = new TreeNode(preorder[0]);
    if(preorder.length == 1){
        return root;
    }
    let leftPreorder = preorder.slice(1, postorder.indexOf(preorder[1]) + 2);
    let rightPreorder = preorder.slice(postorder.indexOf(preorder[1]) + 2);
    let leftPostorder = postorder.slice(0, postorder.indexOf(preorder[1]) + 1);
    let rightPostorder = postorder.slice(postorder.indexOf(preorder[1]) + 1, postorder.length - 1);
    root.left = constructFromPrePost(leftPreorder, leftPostorder);
    root.right = constructFromPrePost(rightPreorder, rightPostorder);
    return root;
    
};

    