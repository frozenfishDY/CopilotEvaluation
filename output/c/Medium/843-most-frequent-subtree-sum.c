/**https://leetcode.com/problems/most-frequent-subtree-sum/ */
//Given the root of a binary tree, return the most frequent subtree sum. If there is a tie, return all the values with the highest frequency in any order.
//The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself).
// 
//Example 1:
//Input: root = [5,2,-3]
//Output: [2,-3,4]
//Example 2:
//Input: root = [5,2,-5]
//Output: [2]
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 104].
//	-105 <= Node.val <= 105
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
int* findFrequentTreeSum(struct TreeNode* root, int* returnSize){
int* res = (int*)malloc(sizeof(int) * 10000);
    *returnSize = 0;
    if (root == NULL) {
        return res;
    }
    int* hash = (int*)malloc(sizeof(int) * 10000);
    memset(hash, 0, sizeof(int) * 10000);
    int max = 0;
    dfs(root, hash, returnSize, &max);
    for (int i = 0; i < 10000; i++) {
        if (hash[i] == max) {
            res[(*returnSize)++] = i;
        }
    }
    return res;
}
int dfs(struct TreeNode* root, int* hash, int* returnSize, int* max) {
    if (root == NULL) {
        return 0;
    }
    int left = dfs(root->left, hash, returnSize, max);
    int right = dfs(root->right, hash, returnSize, max);
    int sum = left + right + root->val;
    hash[sum]++;
    if (hash[sum] > *max) {
        *max = hash[sum];
    }
    return sum;
}