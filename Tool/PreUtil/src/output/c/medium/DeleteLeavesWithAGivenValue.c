/**https://leetcode.com/problems/delete-leaves-with-a-given-value/ */
//Given a binary tree root and an integer target, delete all the leaf nodes with value target.
//Note that once you delete a leaf node with value target, if its parent node becomes a leaf node and has the value target, it should also be deleted (you need to continue doing that until you cannot).


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* removeLeafNodes(struct TreeNode* root, int target){
    if(root == NULL){
        return NULL;
    }
    root->left = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);
    if(root->left == NULL && root->right == NULL && root->val == target){
        return NULL;
    }
    return root;

}

    