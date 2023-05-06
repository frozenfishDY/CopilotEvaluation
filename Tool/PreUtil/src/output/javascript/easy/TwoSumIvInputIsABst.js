/**https://leetcode.com/problems/two-sum-iv-input-is-a-bst/ */
//Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.


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
 * @param {number} k
 * @return {boolean}
 */
var findTarget = function(root, k) {
    let set = new Set();
    let queue = [root];
    while(queue.length > 0){
        let node = queue.shift();
        if(set.has(k - node.val)){
            return true;
        }
        set.add(node.val);
        if(node.left != null){
            queue.push(node.left);
        }
        if(node.right != null){
            queue.push(node.right);
        }
    }
    return false;
    
};

    