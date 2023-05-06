/**https://leetcode.com/problems/delete-node-in-a-bst/ */
//Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.
//Basically, the deletion can be divided into two stages:
//Search for a node to remove.
//If the node is found, delete the node.


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
 * @param {number} key
 * @return {TreeNode}
 */
var deleteNode = function(root, key) {
    if(root == null){
        return null;
    }
    if(root.val == key){
        if(root.left == null){
            return root.right;
        }
        if(root.right == null){
            return root.left;
        }
        let temp = root.right;
        while(temp.left != null){
            temp = temp.left;
        }
        root.val = temp.val;
        root.right = deleteNode(root.right, temp.val);
    }
    else if(root.val > key){
        root.left = deleteNode(root.left, key);
    }
    else{
        root.right = deleteNode(root.right, key);
    }
    return root;
    
};

    