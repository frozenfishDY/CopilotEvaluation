/**https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/ */
//You are given the root of a binary tree with n nodes, where each node is uniquely assigned a value from 1 to n. You are also given a sequence of n values voyage, which is the desired pre-order traversal of the binary tree.
//Any node in the binary tree can be flipped by swapping its left and right subtrees. For example, flipping node 1 will have the following effect:
//Flip the smallest number of nodes so that the pre-order traversal of the tree matches voyage.
//Return a list of the values of all flipped nodes. You may return the answer in any order. If it is impossible to flip the nodes in the tree to make the pre-order traversal match voyage, return the list [-1].


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
 * @param {number[]} voyage
 * @return {number[]}
 */
var flipMatchVoyage = function(root, voyage) {
    let result = [];
    let i = 0;
    let flag = true;
    function dfs(root){
        if(root == null){
            return;
        }
        if(root.val != voyage[i]){
            flag = false;
            return;
        }
        i++;
        if(root.left != null && root.left.val != voyage[i]){
            result.push(root.val);
            dfs(root.right);
            dfs(root.left);
        }else{
            dfs(root.left);
            dfs(root.right);
        }
    }
    dfs(root);
    if(flag == false){
        return [-1];
    }
    return result;
    
};

    