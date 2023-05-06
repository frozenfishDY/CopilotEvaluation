/**https://leetcode.com/problems/all-elements-in-two-binary-search-trees/ */
//Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.


/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root1
 * @param {TreeNode} root2
 * @return {number[]}
 */
var getAllElements = function(root1, root2) {
    let result = [];
    let dfs = function(node){
        if(node == null){
            return;
        }
        result.push(node.val);
        dfs(node.left);
        dfs(node.right);
    }
    dfs(root1);
    dfs(root2);
    result.sort((a, b) => a - b);
    return result;
    
};

    