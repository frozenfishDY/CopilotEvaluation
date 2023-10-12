/**https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/ */
//You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.
//Each minute, a node becomes infected if:
//	The node is currently uninfected.
//	The node is adjacent to an infected node.
//Return the number of minutes needed for the entire tree to be infected.
// 
//Example 1:
//Input: root = [1,5,3,null,4,10,6,9,2], start = 3
//Output: 4
//Explanation: The following nodes are infected during:
//- Minute 0: Node 3
//- Minute 1: Nodes 1, 10 and 6
//- Minute 2: Node 5
//- Minute 3: Node 4
//- Minute 4: Nodes 9 and 2
//It takes 4 minutes for the whole tree to be infected so we return 4.
//Example 2:
//Input: root = [1], start = 1
//Output: 0
//Explanation: At minute 0, the only node in the tree is infected so we return 0.
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 105].
//	1 <= Node.val <= 105
//	Each node has a unique value.
//	A node with a value of start exists in the tree.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int amountOfTime(struct TreeNode* root, int start){
int i, j;
	int *cnt = (int *)malloc(sizeof(int) * 100001);
	memset(cnt, 0, sizeof(int) * 100001);
	cnt[start] = 1;
	struct TreeNode **q = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * 100001);
	int front = 0, rear = 0;
	q[rear++] = root;
	while (front != rear) {
		struct TreeNode *node = q[front++];
		if (node->left != NULL) {
			q[rear++] = node->left;
			if (node->left->val != start) {
				cnt[node->left->val] = 1;
			}
		}
		if (node->right != NULL) {
			q[rear++] = node->right;
			if (node->right->val != start) {
				cnt[node->right->val] = 1;
			}
		}
	}
	int max = 0;
	for (i = 0; i < 100001; ++i) {
		if (cnt[i] > max) {
			max = cnt[i];
		}
	}
	return max - 1;
}