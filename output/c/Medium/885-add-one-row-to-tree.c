/**https://leetcode.com/problems/add-one-row-to-tree/ */
//Given the root of a binary tree and two integers val and depth, add a row of nodes with value val at the given depth depth.
//Note that the root node is at depth 1.
//The adding rule is:
//	Given the integer depth, for each not null tree node cur at the depth depth - 1, create two tree nodes with value val as cur's left subtree root and right subtree root.
//	cur's original left subtree should be the left subtree of the new left subtree root.
//	cur's original right subtree should be the right subtree of the new right subtree root.
//	If depth == 1 that means there is no depth depth - 1 at all, then create a tree node with value val as the new root of the whole original tree, and the original tree is the new root's left subtree.
// 
//Example 1:
//Input: root = [4,2,6,3,1,5], val = 1, depth = 2
//Output: [4,1,1,2,null,null,6,3,1,5]
//Example 2:
//Input: root = [4,2,null,3,1], val = 1, depth = 3
//Output: [4,2,null,1,1,3,null,null,1]
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 104].
//	The depth of the tree is in the range [1, 104].
//	-100 <= Node.val <= 100
//	-105 <= val <= 105
//	1 <= depth <= the depth of tree + 1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* addOneRow(struct TreeNode* root, int val, int depth){
if (depth == 1) {
        struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        node->val = val;
        node->left = root;
        node->right = NULL;
        return node;
    }
    int i = 0;
    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 1000);
    int queueSize = 0;
    queue[queueSize++] = root;
    while (i < depth - 2) {
        int size = queueSize;
        for (int j = 0; j < size; j++) {
            struct TreeNode* node = queue[0];
            queueSize--;
            queue++;
            if (node->left != NULL) {
                queue[queueSize++] = node->left;
            }
            if (node->right != NULL) {
                queue[queueSize++] = node->right;
            }
        }
        i++;
    }
    while (queueSize != 0) {
        struct TreeNode* node = queue[0];
        queueSize--;
        queue++;
        struct TreeNode* left = node->left;
        struct TreeNode* right = node->right;
        struct TreeNode* leftNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        struct TreeNode* rightNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        leftNode->val = val;
        rightNode->val = val;
        leftNode->left = left;
        rightNode->right = right;
        node->left = leftNode;
        node->right = rightNode;
    }
    return root;
}