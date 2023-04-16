/**https://leetcode.com/problems/sum-of-left-leaves/ */
//Given the root of a binary tree, return the sum of all left leaves.
//A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumOfLeftLeaves(struct TreeNode* root){
    if(root == NULL){
        return 0;
    }
    int sum = 0;
    if(root->left != NULL && root->left->left == NULL && root->left->right == NULL){
        sum += root->left->val;
    }
    sum += sumOfLeftLeaves(root->left);
    sum += sumOfLeftLeaves(root->right);
    return sum;

}

    