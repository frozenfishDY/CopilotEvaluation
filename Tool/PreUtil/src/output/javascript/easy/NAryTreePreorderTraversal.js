/**https://leetcode.com/problems/n-ary-tree-preorder-traversal/ */
//Given the root of an n-ary tree, return the preorder traversal of its nodes' values.
//Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)


/**
 * // Definition for a Node.
 * function Node(val, children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */

/**
 * @param {Node|null} root
 * @return {number[]}
 */
var preorder = function(root) {
    let result = [];
    let stack = [];
    if(root != null){
        stack.push(root);
    }
    while(stack.length > 0){
        let current = stack.pop();
        result.push(current.val);
        for(let i = current.children.length - 1; i >= 0; i--){
            stack.push(current.children[i]);
        }
    }
    return result;
    
};

    