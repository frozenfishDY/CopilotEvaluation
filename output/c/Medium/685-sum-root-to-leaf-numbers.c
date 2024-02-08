/**https://leetcode.com/problems/sum-root-to-leaf-numbers/ */
//You are given the root of a binary tree containing digits from 0 to 9 only.
//Each root-to-leaf path in the tree represents a number.
//For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
//Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.
//A leaf node is a node with no children.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumNumbers(struct TreeNode* root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return root->val;
    }
    int sum = 0;
    if(root->left != NULL){
        root->left->val += root->val * 10;
        sum += sumNumbers(root->left);
    }
    if(root->right != NULL){
        root->right->val += root->val * 10;
        sum += sumNumbers(root->right);
    }
    return sum;

}

    