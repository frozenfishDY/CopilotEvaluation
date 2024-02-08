/**https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/ */
//Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.
//As a reminder, a binary search tree is a tree that satisfies these constraints:
//The left subtree of a node contains only nodes with keys less than the node's key.
//The right subtree of a node contains only nodes with keys greater than the node's key.
//Both the left and right subtrees must also be binary search trees.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* bstToGst(struct TreeNode* root){
    if(root == NULL){
        return NULL;
    }
    if(root->right != NULL){
        bstToGst(root->right);
    }
    if(root->left != NULL){
        bstToGst(root->left);
    }
    if(root->right != NULL){
        root->val += root->right->val;
    }
    if(root->left != NULL){
        root->left->val += root->val;
    }
    return root;

}

    