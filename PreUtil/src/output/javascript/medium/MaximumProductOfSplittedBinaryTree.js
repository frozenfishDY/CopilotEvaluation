/**https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/ */
//Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.
//Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.
//Note that you need to maximize the answer before taking the mod and not after taking it.


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
var maxProduct = function(root) {
    let total = 0;
    let dfs = function(node){
        if(node == null){
            return 0;
        }
        let left = dfs(node.left);
        let right = dfs(node.right);
        total += node.val;
        return left + right + node.val;
    }
    let max = 0;
    let sum = dfs(root);
    dfs = function(node){
        if(node == null){
            return 0;
        }
        let left = dfs(node.left);
        let right = dfs(node.right);
        let current = left + right + node.val;
        let other = sum - current;
        let product = current * other;
        if(product > max){
            max = product;
        }
        return current;
    }
    dfs(root);
    return max % (10 ** 9 + 7);
    
};

    