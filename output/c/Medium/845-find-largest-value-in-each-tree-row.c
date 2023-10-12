/**https://leetcode.com/problems/find-largest-value-in-each-tree-row/ */
//Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).
// 
//Example 1:
//Input: root = [1,3,2,5,3,null,9]
//Output: [1,3,9]
//Example 2:
//Input: root = [1,2,3]
//Output: [1,3]
// 
//Constraints:
//	The number of nodes in the tree will be in the range [0, 104].
//	-231 <= Node.val <= 231 - 1
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
int* largestValues(struct TreeNode* root, int* returnSize){
int* res = (int*)malloc(sizeof(int) * 10000);
	*returnSize = 0;
	if (root == NULL) {
		return res;
	}
	struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 10000);
	int queueSize = 0;
	queue[queueSize++] = root;
	while (queueSize != 0) {
		int size = queueSize;
		int max = INT_MIN;
		for (int i = 0; i < size; i++) {
			struct TreeNode* node = queue[0];
			queueSize--;
			queue++;
			if (node->val > max) {
				max = node->val;
			}
			if (node->left != NULL) {
				queue[queueSize++] = node->left;
			}
			if (node->right != NULL) {
				queue[queueSize++] = node->right;
			}
		}
		res[(*returnSize)++] = max;
	}
	return res;
}