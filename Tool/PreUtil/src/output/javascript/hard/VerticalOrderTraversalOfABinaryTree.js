/**https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/ */
//Given the root of a binary tree, calculate the vertical order traversal of the binary tree.
//For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).
//The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.
//Return the vertical order traversal of the binary tree.


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
 * @return {number[][]}
 */
var verticalTraversal = function(root) {
    let map = new Map();
    let dfs = function(node, row, col){
        if(node === null){
            return;
        }
        if(!map.has(col)){
            map.set(col, []);
        }
        map.get(col).push([row, node.val]);
        dfs(node.left, row + 1, col - 1);
        dfs(node.right, row + 1, col + 1);
    }
    dfs(root, 0, 0);
    let res = [];
    let keys = [...map.keys()].sort((a, b) => a - b);
    for(let key of keys){
        let arr = map.get(key);
        arr.sort((a, b) => {
            if(a[0] === b[0]){
                return a[1] - b[1];
            }
            return a[0] - b[0];
        });
        let temp = [];
        for(let i = 0; i < arr.length; i++){
            temp.push(arr[i][1]);
        }
        res.push(temp);
    }
    return res;

    
};

    