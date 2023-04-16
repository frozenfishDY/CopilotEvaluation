/**https://leetcode.com/problems/all-elements-in-two-binary-search-trees/ */
//Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.


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
int* getAllElements(struct TreeNode* root1, struct TreeNode* root2, int* returnSize){
    int* result = malloc(10000 * sizeof(int));
    int resultSize = 0;
    struct TreeNode* queue[10000];
    int queueSize = 0;
    queue[queueSize++] = root1;
    while(queueSize > 0){
        int size = queueSize;
        queueSize = 0;
        for(int i = 0; i < size; i++){
            struct TreeNode* node = queue[i];
            result[resultSize++] = node->val;
            if(node->left != NULL){
                queue[queueSize++] = node->left;
            }
            if(node->right != NULL){
                queue[queueSize++] = node->right;
            }
        }
    }
    queue[queueSize++] = root2;
    while(queueSize > 0){
        int size = queueSize;
        queueSize = 0;
        for(int i = 0; i < size; i++){
            struct TreeNode* node = queue[i];
            result[resultSize++] = node->val;
            if(node->left != NULL){
                queue[queueSize++] = node->left;
            }
            if(node->right != NULL){
                queue[queueSize++] = node->right;
            }
        }
    }
    *returnSize = resultSize;
    return result;

}

    