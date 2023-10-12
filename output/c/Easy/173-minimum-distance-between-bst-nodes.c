/**https://leetcode.com/problems/minimum-distance-between-bst-nodes/ */
//Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.
// 
//Example 1:
//Input: root = [4,2,6,1,3]
//Output: 1
//Example 2:
//Input: root = [1,0,48,null,null,12,49]
//Output: 1
// 
//Constraints:
//	The number of nodes in the tree is in the range [2, 100].
//	0 <= Node.val <= 105
// 
//Note: This question is the same as 530: https://leetcode.com/problems/minimum-absolute-difference-in-bst/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDiffInBST(struct TreeNode* root){
int minDiff = INT_MAX, prev = -1;
  traverse(root, &prev, &minDiff);
  return minDiff;
}
void traverse(struct TreeNode* root, int* prev, int* minDiff) {
  if(root == NULL) {
    return;
  }
  traverse(root->left, prev, minDiff);
  if(*prev != -1 && root->val - *prev < *minDiff) {
    *minDiff = root->val - *prev;
  }
  *prev = root->val;
  traverse(root->right, prev, minDiff);
}