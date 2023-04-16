/**https://leetcode.com/problems/all-possible-full-binary-trees/ */
//Given an integer n, return a list of all possible full binary trees with n nodes. Each node of each tree in the answer must have Node.val == 0.
//Each element of the answer is the root node of one possible tree. You may return the final list of trees in any order.
//A full binary tree is a binary tree where each node has exactly 0 or 2 children.


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
struct TreeNode** allPossibleFBT(int n, int* returnSize){
    struct TreeNode** result = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 10000);
    *returnSize = 0;
    if(n == 1){
        struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        node->val = 0;
        node->left = NULL;
        node->right = NULL;
        result[*returnSize] = node;
        (*returnSize)++;
        return result;
    }
    for(int i = 1; i < n; i += 2){
        int leftSize = 0;
        int rightSize = 0;
        struct TreeNode** left = allPossibleFBT(i, &leftSize);
        struct TreeNode** right = allPossibleFBT(n - i - 1, &rightSize);
        for(int j = 0; j < leftSize; j++){
            for(int k = 0; k < rightSize; k++){
                struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                node->val = 0;
                node->left = left[j];
                node->right = right[k];
                result[*returnSize] = node;
                (*returnSize)++;
            }
        }
    }
    return result;

}

    