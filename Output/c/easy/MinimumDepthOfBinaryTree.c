/**https://leetcode.com/problems/minimum-depth-of-binary-tree/ */
//Given a binary tree, find its minimum depth.
//The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
//Note: A leaf is a node with no children.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root){
    if(root == NULL){
        return 0;
    }
    int left = minDepth(root->left);
    int right = minDepth(root->right);
    if(left == 0 || right == 0){
        return left + right + 1;
    }
    return left < right ? left + 1 : right + 1;

}
    