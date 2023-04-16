/**https://leetcode.com/problems/binary-tree-tilt/ */
//Given the root of a binary tree, return the sum of every tree node's tilt.
//The tilt of a tree node is the absolute difference between the sum of all left subtree node values and all right subtree node values. If a node does not have a left child, then the sum of the left subtree node values is treated as 0. The rule is similar if the node does not have a right child.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int findTilt(struct TreeNode* root){
    if(root == NULL){
        return 0;
    }
    int left = findTilt(root->left);
    int right = findTilt(root->right);
    int sum = 0;
    if(root->left != NULL){
        sum += root->left->val;
    }
    if(root->right != NULL){
        sum += root->right->val;
    }
    return abs(sum - root->val) + left + right;

}

    