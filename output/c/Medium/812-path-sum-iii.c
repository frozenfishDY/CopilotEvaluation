/**https://leetcode.com/problems/path-sum-iii/ */
//Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.
//The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int pathSum(struct TreeNode* root, int targetSum){
    if(root == NULL){
        return 0;
    }
    int count = 0;
    int sum = 0;
    int* dp = (int*)malloc(sizeof(int) * 1000);
    for(int i = 0; i < 1000; i++){
        dp[i] = 0;
    }
    dp[0] = 1;
    pathSumHelper(root, targetSum, dp, &count, sum);
    return count;

}

    