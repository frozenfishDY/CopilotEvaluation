/**https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/ */
//You are given the root of a binary tree and an integer distance. A pair of two different leaf nodes of a binary tree is said to be good if the length of the shortest path between them is less than or equal to distance.
//Return the number of good leaf node pairs in the tree.


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
 * @param {number} distance
 * @return {number}
 */
var countPairs = function(root, distance) {
    let res = 0;
    let dfs = (node) => {
        if (!node) {
            return [];
        }
        if (!node.left && !node.right) {
            return [1];
        }
        let left = dfs(node.left);
        let right = dfs(node.right);
        for (let i = 0; i < left.length; i++) {
            for (let j = 0; j < right.length; j++) {
                if (left[i] + right[j] <= distance) {
                    res++;
                }
            }
        }
        let res = [];
        for (let i = 0; i < left.length; i++) {
            if (left[i] + 1 < distance) {
                res.push(left[i] + 1);
            }
        }
        for (let i = 0; i < right.length; i++) {
            if (right[i] + 1 < distance) {
                res.push(right[i] + 1);
            }
        }
        return res;
    }
    dfs(root);
    return res;
    
};

    