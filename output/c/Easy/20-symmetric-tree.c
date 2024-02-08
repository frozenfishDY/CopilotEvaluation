/**https://leetcode.com/problems/symmetric-tree/ */
//Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSymmetric(struct TreeNode* root){
    if(root == NULL){
        return true;
    }
    return isSymmetricTree(root->left, root->right);

}
    