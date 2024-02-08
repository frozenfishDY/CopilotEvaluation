/**https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/ */
//Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    if(inorderSize == 0){
        return NULL;
    }
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = postorder[postorderSize - 1];
    root->left = NULL;
    root->right = NULL;
    int i = 0;
    for(i = 0; i < inorderSize; i++){
        if(inorder[i] == postorder[postorderSize - 1]){
            break;
        }
    }
    root->left = buildTree(inorder, i, postorder, i);
    root->right = buildTree(inorder + i + 1, inorderSize - i - 1, postorder + i, postorderSize - i - 1);
    return root;

}

    