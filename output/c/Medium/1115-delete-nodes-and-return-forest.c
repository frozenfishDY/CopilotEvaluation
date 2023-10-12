/**https://leetcode.com/problems/delete-nodes-and-return-forest/ */
//Given the root of a binary tree, each node in the tree has a distinct value.
//After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).
//Return the roots of the trees in the remaining forest. You may return the result in any order.
// 
//Example 1:
//Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
//Output: [[1,2,null,4],[6],[7]]
//Example 2:
//Input: root = [1,2,4,null,3], to_delete = [3]
//Output: [[1,2,4]]
// 
//Constraints:
//	The number of nodes in the given tree is at most 1000.
//	Each node has a distinct value between 1 and 1000.
//	to_delete.length <= 1000
//	to_delete contains distinct values between 1 and 1000.
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
struct TreeNode** delNodes(struct TreeNode* root, int* to_delete, int to_deleteSize, int* returnSize){
int *delete = (int *)malloc(sizeof(int) * 1001);
    memset(delete, 0, sizeof(int) * 1001);
    for (int i = 0; i < to_deleteSize; ++i) {
        delete[to_delete[i]] = 1;
    }
    struct TreeNode **res = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * 1001);
    *returnSize = 0;
    if (!delete[root->val]) {
        res[*returnSize] = root;
        ++*returnSize;
    }
    dfs(root, delete, res, returnSize);
    return res;
}
void dfs(struct TreeNode *root, int *delete, struct TreeNode **res, int *returnSize) {
    if (!root) {
        return;
    }
    if (delete[root->val]) {
        if (root->left && !delete[root->left->val]) {
            res[*returnSize] = root->left;
            ++*returnSize;
        }
        if (root->right && !delete[root->right->val]) {
            res[*returnSize] = root->right;
            ++*returnSize;
        }
    }
    dfs(root->left, delete, res, returnSize);
    dfs(root->right, delete, res, returnSize);
    if (root->left && delete[root->left->val]) {
        root->left = NULL;
    }
    if (root->right && delete[root->right->val]) {
        root->right = NULL;
    }
}