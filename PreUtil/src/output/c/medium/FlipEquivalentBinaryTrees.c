/**https://leetcode.com/problems/flip-equivalent-binary-trees/ */
//For a binary tree T, we can define a flip operation as follows: choose any node, and swap the left and right child subtrees.
//A binary tree X is flip equivalent to a binary tree Y if and only if we can make X equal to Y after some number of flip operations.
//Given the roots of two binary trees root1 and root2, return true if the two trees are flip equivalent or false otherwise.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool flipEquiv(struct TreeNode* root1, struct TreeNode* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    if(root1 == NULL || root2 == NULL){
        return false;
    }
    if(root1->val != root2->val){
        return false;
    }
    return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) || (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));

}

    