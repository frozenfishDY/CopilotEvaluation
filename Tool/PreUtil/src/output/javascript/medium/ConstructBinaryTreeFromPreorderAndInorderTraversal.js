/**https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/ */
//Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.


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
 * @param {number[]} inorder
 * @return {TreeNode}
 */
var buildTree = function(preorder, inorder) {
    if(preorder.length == 0 || inorder.length == 0){
        return null;
    }
    let root = new TreeNode(preorder[0]);
    let rootIndex = inorder.indexOf(preorder[0]);
    let leftInorder = inorder.slice(0, rootIndex);
    let rightInorder = inorder.slice(rootIndex + 1);
    let leftPreorder = preorder.slice(1, leftInorder.length + 1);
    let rightPreorder = preorder.slice(leftInorder.length + 1);
    root.left = buildTree(leftPreorder, leftInorder);
    root.right = buildTree(rightPreorder, rightInorder);
    return root;
    
};

    