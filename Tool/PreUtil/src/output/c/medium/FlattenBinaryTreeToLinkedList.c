/**https://leetcode.com/problems/flatten-binary-tree-to-linked-list/ */
//Given the root of a binary tree, flatten the tree into a "linked list":
//The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
//The "linked list" should be in the same order as a pre-order traversal of the binary tree.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void flatten(struct TreeNode* root){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        return;
    }
    if(root->left != NULL){
        flatten(root->left);
        struct TreeNode* temp = root->right;
        root->right = root->left;
        root->left = NULL;
        struct TreeNode* temp1 = root->right;
        while(temp1->right != NULL){
            temp1 = temp1->right;
        }
        temp1->right = temp;
    }
    flatten(root->right);

}

    