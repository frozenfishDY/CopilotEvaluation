/**https://leetcode.com/problems/binary-tree-paths/ */
//Given the root of a binary tree, return all root-to-leaf paths in any order.
//A leaf is a node with no children.
// 
//Example 1:
//Input: root = [1,2,3,null,5]
//Output: ["1->2->5","1->3"]
//Example 2:
//Input: root = [1]
//Output: ["1"]
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 100].
//	-100 <= Node.val <= 100
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
char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
      char **res = (char **)malloc(sizeof(char *) * 1000);
        int i = 0;
        if (root == NULL) {
            *returnSize = 0;
            return res;
        }
        if (root->left == NULL && root->right == NULL) {
            res[i] = (char *)malloc(sizeof(char) * 1000);
            sprintf(res[i], "%d", root->val);
            *returnSize = 1;
            return res;
        }
        int leftSize = 0, rightSize = 0;
        char **left = binaryTreePaths(root->left, &leftSize);
        char **right = binaryTreePaths(root->right, &rightSize);
        for (i = 0; i < leftSize; i++) {
            res[i] = (char *)malloc(sizeof(char) * 1000);
            sprintf(res[i], "%d->%s", root->val, left[i]);
        }
        for (i = 0; i < rightSize; i++) {
            res[i + leftSize] = (char *)malloc(sizeof(char) * 1000);
            sprintf(res[i + leftSize], "%d->%s", root->val, right[i]);
        }
        *returnSize = leftSize + rightSize;
        return res;      
 
 
 
   

        
}