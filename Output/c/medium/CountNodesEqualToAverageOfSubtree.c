/**https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/ */
//Given the root of a binary tree, return the number of nodes where the value of the node is equal to the average of the values in its subtree.
//Note:
//The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
//A subtree of root is a tree consisting of root and all of its descendants.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int averageOfSubtree(struct TreeNode* root){
    int sum = 0, count = 0;
    if(root == NULL){
        return 0;
    }
    sum = root->val;
    count++;
    if(root->left != NULL){
        sum += averageOfSubtree(root->left);
        count++;
    }
    if(root->right != NULL){
        sum += averageOfSubtree(root->right);
        count++;
    }
    return sum/count;

}

    