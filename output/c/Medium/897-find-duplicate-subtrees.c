/**https://leetcode.com/problems/find-duplicate-subtrees/ */
//Given the root of a binary tree, return all duplicate subtrees.
//For each kind of duplicate subtrees, you only need to return the root node of any one of them.
//Two trees are duplicate if they have the same structure with the same node values.
// 
//Example 1:
//Input: root = [1,2,3,4,null,2,4,null,null,4]
//Output: [[2,4],[4]]
//Example 2:
//Input: root = [2,1,1]
//Output: [[1]]
//Example 3:
//Input: root = [2,2,2,3,null,3,null]
//Output: [[2,3],[3]]
// 
//Constraints:
//	The number of the nodes in the tree will be in the range [1, 5000]
//	-200 <= Node.val <= 200
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
struct TreeNode** findDuplicateSubtrees(struct TreeNode* root, int* returnSize){
struct TreeNode** res = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 1000);
	*returnSize = 0;
	if (root == NULL) {
		return res;
	}
	struct TreeNode** stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 1000);
	int top = -1;
	struct TreeNode* pre = NULL;
	while (root != NULL || top != -1) {
		while (root != NULL) {
			stack[++top] = root;
			root = root->left;
		}
		root = stack[top--];
		if (root->right == NULL || root->right == pre) {
			res[(*returnSize)++] = root;
			pre = root;
			root = NULL;
		} else {
			stack[++top] = root;
			root = root->right;
		}
	}
	return res;
}