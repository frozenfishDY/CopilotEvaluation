/**https://leetcode.com/problems/maximum-depth-of-n-ary-tree/ */
//Given a n-ary tree, find its maximum depth.
//The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
//Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).


/**
 * // Definition for a Node.
 * function Node(val,children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */

/**
 * @param {Node|null} root
 * @return {number}
 */
var maxDepth = function(root) {
    if(root == null){
        return 0;
    }
    let max = 0;
    for(let child of root.children){
        max = Math.max(max, maxDepth(child));
    }
    return max + 1;
    
};

    