/**https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/ */
//We run a preorder depth-first search (DFS) on the root of a binary tree.
//At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.
//If a node has only one child, that child is guaranteed to be the left child.
//Given the output traversal of this traversal, recover the tree and return its root.


/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {string} traversal
 * @return {TreeNode}
 */
var recoverFromPreorder = function(traversal) {
    let stack = [];
    let i = 0;
    while(i < traversal.length){
        let level = 0;
        while(traversal[i] == '-'){
            level++;
            i++;
        }
        let val = 0;
        while(i < traversal.length && traversal[i] != '-'){
            val = val * 10 + traversal[i].charCodeAt(0) - '0'.charCodeAt(0);
            i++;
        }
        let node = new TreeNode(val);
        if(level == stack.length){
            if(stack.length > 0){
                stack[stack.length - 1].left = node;
            }
        }
        else{
            stack = stack.slice(0, level);
            stack[stack.length - 1].right = node;
        }
        stack.push(node);
    }
    return stack[0];
    
};

    