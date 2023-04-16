/**https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/ */
//Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.
//It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.
//A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.
//A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* bstFromPreorder(int* preorder, int preorderSize){
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
    for(i = 0; i < preorderSize; i++){
        if(preorder[i] > preorder[0]){
            break;
        }
    }
    root->left = bstFromPreorder(preorder + 1, i - 1);
    root->right = bstFromPreorder(preorder + i, preorderSize - i);
    return root;

}

    