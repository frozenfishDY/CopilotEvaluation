/**https://leetcode.com/problems/find-bottom-left-tree-value/ */
//Given the root of a binary tree, return the leftmost value in the last row of the tree.
// 
//Example 1:
//Input: root = [2,1,3]
//Output: 1
//Example 2:
//Input: root = [1,2,3,4,null,5,6,null,null,7]
//Output: 7
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 104].
//	-231 <= Node.val <= 231 - 1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int findBottomLeftValue(struct TreeNode* root){
int res = 0;
	struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 10000);
	int queueSize = 0;
	queue[queueSize++] = root;
	while (queueSize != 0) {
		int size = queueSize;
		for (int i = 0; i < size; i++) {
			struct TreeNode* node = queue[0];
			queueSize--;
			queue++;
			if (i == 0) {
				res = node->val;
			}
			if (node->left != NULL) {
				queue[queueSize++] = node->left;
			}
			if (node->right != NULL) {
				queue[queueSize++] = node->right;
			}
		}
	}
	return res;
}