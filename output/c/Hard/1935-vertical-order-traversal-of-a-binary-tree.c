/**https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/ */
//Given the root of a binary tree, calculate the vertical order traversal of the binary tree.
//For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).
//The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.
//Return the vertical order traversal of the binary tree.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** verticalTraversal(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int** result = (int**)malloc(sizeof(int*) * 10 * strlen(target));
    *returnSize = 10 * strlen(target);
    return result;

}

    