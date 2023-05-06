/**https://leetcode.com/problems/binary-tree-inorder-traversal/ */
//Given the root of a binary tree, return the inorder traversal of its nodes' values.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int *result = (int *)malloc(sizeof(int) * 100);
    int index = 0;
    struct TreeNode *p = root;
    struct TreeNode *pre = NULL;
    while(p != NULL){
        if(p->left == NULL){
            result[index++] = p->val;
            p = p->right;
        }else{
            pre = p->left;
            while(pre->right != NULL && pre->right != p){
                pre = pre->right;
            }
            if(pre->right == NULL){
                pre->right = p;
                p = p->left;
            }else{
                pre->right = NULL;
                result[index++] = p->val;
                p = p->right;
            }
        }
    }
    *returnSize = index;
    return result;

}
    