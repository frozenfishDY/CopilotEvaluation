/**https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/ */
//Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.
//Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.
//Note that you need to maximize the answer before taking the mod and not after taking it.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxProduct(struct TreeNode* root){
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

    