/**https://leetcode.com/problems/longest-univalue-path/ */
//Given the root of a binary tree, return the length of the longest path, where each node in the path has the same value. This path may or may not pass through the root.
//The length of the path between two nodes is represented by the number of edges between them.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int longestUnivaluePath(struct TreeNode* root){
    int max = 0;
    int* maxPtr = &max;
    longestUnivaluePathHelper(root, maxPtr);
    return max;

}

    