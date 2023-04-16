/**https://leetcode.com/problems/binary-tree-maximum-path-sum/ */
//A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
//The path sum of a path is the sum of the node's values in the path.
//Given the root of a binary tree, return the maximum path sum of any non-empty path.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxPathSum(struct TreeNode* root){
    int max = root->val;
    int maxPathSumHelper(struct TreeNode* root, int *max) {
        if (root == NULL) {
            return 0;
        }
        int left = maxPathSumHelper(root->left, max);
        int right = maxPathSumHelper(root->right, max);
        int sum = root->val;
        if (left > 0) {
            sum += left;
        }
        if (right > 0) {
            sum += right;
        }
        if (sum > *max) {
            *max = sum;
        }
        if (left > right) {
            if (left > 0) {
                return left + root->val;
            } else {
                return root->val;
            }
        } else {
            if (right > 0) {
                return right + root->val;
            } else {
                return root->val;
            }
        }
    }
    maxPathSumHelper(root, &max);
    return max;

}

    