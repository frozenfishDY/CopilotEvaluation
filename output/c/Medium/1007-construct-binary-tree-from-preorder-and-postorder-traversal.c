/**https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/ */
//Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.
//If there exist multiple answers, you can return any of them.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* constructFromPrePost(int* preorder, int preorderSize, int* postorder, int postorderSize){
    if(preorderSize == 0){
        return NULL;
    }
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    root->left = NULL;
    root->right = NULL;
    if(preorderSize == 1){
        return root;
    }
    int i = 0;
    for(i = 0; i < postorderSize; i++){
        if(postorder[i] == preorder[1]){
            break;
        }
    }
    root->left = constructFromPrePost(preorder + 1, i + 1, postorder, i + 1);
    root->right = constructFromPrePost(preorder + i + 2, preorderSize - i - 2, postorder + i + 1, postorderSize - i - 2);
    return root;

}

    