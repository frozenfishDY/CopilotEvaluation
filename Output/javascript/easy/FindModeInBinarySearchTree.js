/**https://leetcode.com/problems/find-mode-in-binary-search-tree/ */
//Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.
//If the tree has more than one mode, return them in any order.
//Assume a BST is defined as follows:
//The left subtree of a node contains only nodes with keys less than or equal to the node's key.
//The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
//Both the left and right subtrees must also be binary search trees.


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
 * @return {number[]}
 */
var findMode = function(root) {
    let map = {};
    let max = 0;
    let ans = [];
    function dfs(root){
        if(root == null){
            return;
        }
        if(map[root.val] == undefined){
            map[root.val] = 1;
        }else{
            map[root.val]++;
        }
        if(map[root.val] > max){
            max = map[root.val];
        }
        dfs(root.left);
        dfs(root.right);
    }
    dfs(root);
    for(let key in map){
        if(map[key] == max){
            ans.push(key);
        }
    }
    return ans;
    
};

    