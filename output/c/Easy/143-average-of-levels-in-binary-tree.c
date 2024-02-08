/**https://leetcode.com/problems/average-of-levels-in-binary-tree/ */
//Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. Answers within 10-5 of the actual answer will be accepted.


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
double* averageOfLevels(struct TreeNode* root, int* returnSize){
    double *result = (double *)malloc(sizeof(double) * 100);
    int *count = (int *)malloc(sizeof(int) * 100);
    int index = 0;
    struct TreeNode *p = root;
    struct TreeNode *pre = NULL;
    while(p != NULL){
        if(p->left == NULL && p->right == NULL){
            result[index] += p->val;
            count[index]++;
            p = p->left;
        }else{
            pre = p->right;
            while(pre->left != NULL && pre->left != p){
                pre = pre->left;
            }
            if(pre->left == NULL){
                pre->left = p;
                result[index] += p->val;
                count[index]++;
                p = p->left;
            }else{
                pre->left = NULL;
                p = p->right;
            }
        }
        if(p == NULL){
            index++;
            p = root;
        }
    }
    *returnSize = index;
    for(int i = 0; i < index; i++){
        result[i] /= count[i];
    }
    return result;

}

    