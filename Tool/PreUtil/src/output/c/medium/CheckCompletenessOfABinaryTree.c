/**https://leetcode.com/problems/check-completeness-of-a-binary-tree/ */
//Given the root of a binary tree, determine if it is a complete binary tree.
//In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isCompleteTree(struct TreeNode* root){
    struct TreeNode* queue[10000];
    int front = 0;
    int rear = 0;
    queue[rear++] = root;
    while(front < rear){
        struct TreeNode* node = queue[front++];
        if(node == NULL){
            break;
        }
        queue[rear++] = node->left;
        queue[rear++] = node->right;
    }
    while(front < rear){
        if(queue[front++] != NULL){
            return false;
        }
    }
    return true;

}

    