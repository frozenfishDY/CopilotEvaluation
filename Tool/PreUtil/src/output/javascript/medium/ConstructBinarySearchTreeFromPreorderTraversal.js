/**https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/ */
//Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.
//It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.
//A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.
//A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.


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
 * @return {TreeNode}
 */
var bstFromPreorder = function(preorder) {
    let n = preorder.length;
    let root = new TreeNode(preorder[0]);
    let stack = [];
    stack.push(root);
    for(let i = 1; i < n; i++){
        let node = new TreeNode(preorder[i]);
        if(preorder[i] < stack[stack.length - 1].val){
            stack[stack.length - 1].left = node;
        }
        else{
            let temp = null;
            while(stack.length > 0 && stack[stack.length - 1].val < preorder[i]){
                temp = stack.pop();
            }
            temp.right = node;
        }
        stack.push(node);
    }
    return root;
    
};

    