/**https://leetcode.com/problems/two-sum-iv-input-is-a-bst/ */
//Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool findTarget(struct TreeNode* root, int k){
    if(root == NULL){
        return false;
    }
    struct TreeNode *p = root;
    struct TreeNode *pre = NULL;
    while(p != NULL){
        if(p->left == NULL && p->right == NULL){
            p = p->left;
        }else{
            pre = p->right;
            while(pre->left != NULL && pre->left != p){
                pre = pre->left;
            }
            if(pre->left == NULL){
                pre->left = p;
                p = p->left;
            }else{
                pre->left = NULL;
                p = p->right;
            }
        }
        if(p == NULL){
            p = root;
        }
    }
    return false;

}

    