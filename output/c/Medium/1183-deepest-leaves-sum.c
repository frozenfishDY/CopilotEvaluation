/**https://leetcode.com/problems/deepest-leaves-sum/ */
//Given the root of a binary tree, return the sum of values of its deepest leaves.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int deepestLeavesSum(struct TreeNode* root){
    int result = 0;
    int maxDepth = 0;
    struct TreeNode* queue[10000];
    int queueSize = 0;
    queue[queueSize++] = root;
    while(queueSize > 0){
        int size = queueSize;
        queueSize = 0;
        result = 0;
        maxDepth++;
        for(int i = 0; i < size; i++){
            struct TreeNode* node = queue[i];
            result += node->val;
            if(node->left != NULL){
                queue[queueSize++] = node->left;
            }
            if(node->right != NULL){
                queue[queueSize++] = node->right;
            }
        }
    }
    return result;

}

    