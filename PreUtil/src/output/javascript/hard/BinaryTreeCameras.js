/**https://leetcode.com/problems/binary-tree-cameras/ */
//You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.
//Return the minimum number of cameras needed to monitor all nodes of the tree.


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
var minCameraCover = function(root) {
    let res = 0;
    let dfs = function(node){
        if(node === null){
            return 2;
        }
        let left = dfs(node.left);
        let right = dfs(node.right);
        if(left === 0 || right === 0){
            res++;
            return 1;
        }
        if(left === 1 || right === 1){
            return 2;
        }
        return 0;
    }
    if(dfs(root) === 0){
        res++;
    }
    return res;
    
};

    