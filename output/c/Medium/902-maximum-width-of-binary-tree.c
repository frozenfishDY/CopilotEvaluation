/**https://leetcode.com/problems/maximum-width-of-binary-tree/ */
//Given the root of a binary tree, return the maximum width of the given tree.
//The maximum width of a tree is the maximum width among all levels.
//The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.
//It is guaranteed that the answer will in the range of a 32-bit signed integer.
// 
//Example 1:
//Input: root = [1,3,2,5,3,null,9]
//Output: 4
//Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).
//Example 2:
//Input: root = [1,3,2,5,null,null,9,6,null,7]
//Output: 7
//Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).
//Example 3:
//Input: root = [1,3,2,5]
//Output: 2
//Explanation: The maximum width exists in the second level with length 2 (3,2).
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 3000].
//	-100 <= Node.val <= 100
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int widthOfBinaryTree(struct TreeNode* root){
if (root == NULL) {
        return 0;
    }
    int res = 0, i = 0, j = 0, k = 0, l = 0, m = 0, n = 0;
    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 3000);
    int queueSize = 0;
    queue[queueSize++] = root;
    while (queueSize != 0) {
        int size = queueSize;
        res = res > size ? res : size;
        for (i = 0; i < size; i++) {
            struct TreeNode* node = queue[0];
            queueSize--;
            queue++;
            if (node != NULL) {
                queue[queueSize++] = node->left;
                queue[queueSize++] = node->right;
            } else {
                queue[queueSize++] = NULL;
                queue[queueSize++] = NULL;
            }
        }
        while (queueSize != 0 && queue[queueSize - 1] == NULL) {
            queueSize--;
        }
        while (queueSize != 0 && queue[0] == NULL) {
            queue++;
            queueSize--;
        }
    }
    return res;
}