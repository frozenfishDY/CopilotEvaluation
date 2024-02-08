/**https://leetcode.com/problems/path-sum-iii/ */
//Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.
//The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).


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
 * @param {number} targetSum
 * @return {number}
 */
var pathSum = function(root, targetSum) {
    let count = 0;
    let map = new Map();
    map.set(0, 1);
    function dfs(root, sum){
        if(root == null){
            return;
        }
        sum += root.val;
        if(map.has(sum - targetSum)){
            count += map.get(sum - targetSum);
        }
        map.set(sum, map.has(sum) ? map.get(sum) + 1 : 1);
        dfs(root.left, sum);
        dfs(root.right, sum);
        map.set(sum, map.get(sum) - 1);
    }
    dfs(root, 0);
    return count;
    
};

    