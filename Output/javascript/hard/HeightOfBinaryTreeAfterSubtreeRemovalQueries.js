/**https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/ */
//You are given the root of a binary tree with n nodes. Each node is assigned a unique value from 1 to n. You are also given an array queries of size m.
//You have to perform m independent queries on the tree where in the ith query you do the following:
//Remove the subtree rooted at the node with the value queries[i] from the tree. It is guaranteed that queries[i] will not be equal to the value of the root.
//Return an array answer of size m where answer[i] is the height of the tree after performing the ith query.
//Note:
//The queries are independent, so the tree returns to its initial state after each query.
//The height of a tree is the number of edges in the longest simple path from the root to some node in the tree.


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
 * @param {number[]} queries
 * @return {number[]}
 */
var treeQueries = function(root, queries) {
    let n = queries.length;
    let ans = new Array(n).fill(0);
    let map = new Map();
    let dfs = (node) => {
        if(node == null){
            return 0;
        }
        let left = dfs(node.left);
        let right = dfs(node.right);
        let height = 1 + Math.max(left, right);
        map.set(node.val, height);
        return height;
    }
    dfs(root);
    let max = 0;
    for(let i = 0; i < n; i++){
        map.delete(queries[i]);
        for(let [key, value] of map){
            max = Math.max(max, value);
        }
        ans[i] = max;
        max = 0;
    }
    return ans;
    
};

    