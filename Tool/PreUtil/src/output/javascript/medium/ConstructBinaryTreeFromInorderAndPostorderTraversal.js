/**https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/ */
//Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.


/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[]} inorder
 * @param {number[]} postorder
 * @return {TreeNode}
 */
var buildTree = function(inorder, postorder) {
    if(inorder.length == 0 || postorder.length == 0){
        return null;
    }
    let root = new TreeNode(postorder[postorder.length - 1]);
    let rootIndex = inorder.indexOf(postorder[postorder.length - 1]);
    let leftInorder = inorder.slice(0, rootIndex);
    let rightInorder = inorder.slice(rootIndex + 1);
    let leftPostorder = postorder.slice(0, leftInorder.length);
    let rightPostorder = postorder.slice(leftInorder.length, postorder.length - 1);
    root.left = buildTree(leftInorder, leftPostorder);
    root.right = buildTree(rightInorder, rightPostorder);
    return root;
    
};

    