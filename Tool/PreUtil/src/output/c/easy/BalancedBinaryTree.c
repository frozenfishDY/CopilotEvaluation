/**https://leetcode.com/problems/balanced-binary-tree/ */
//Given a binary tree, determine if it is height-balanced.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isBalanced(struct TreeNode* root){
    if(root == NULL){
        return true;
    }
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    if(abs(left - right) > 1){
        return false;
    }
    return isBalanced(root->left) && isBalanced(root->right);

}
    