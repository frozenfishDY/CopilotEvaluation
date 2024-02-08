/**https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/ */
//Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.
//You can return the answer in any order.


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
int* distanceK(struct TreeNode* root, struct TreeNode* target, int k, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 10000);
    *returnSize = 0;
    if(root == NULL){
        return result;
    }
    if(k == 0){
        result[*returnSize] = target->val;
        (*returnSize)++;
        return result;
    }
    int* left = distanceK(root->left, target, k, returnSize);
    int* right = distanceK(root->right, target, k, returnSize);
    if(root == target){
        for(int i = 0; i < *returnSize; i++){
            result[i] = left[i];
        }
        for(int i = 0; i < *returnSize; i++){
            result[i + *returnSize] = right[i];
        }
        *returnSize = *returnSize * 2;
        return result;
    }
    for(int i = 0; i < *returnSize; i++){
        result[i] = left[i];
    }
    for(int i = 0; i < *returnSize; i++){
        result[i + *returnSize] = right[i];
    }
    *returnSize = *returnSize * 2;
    return result;
   
}
   