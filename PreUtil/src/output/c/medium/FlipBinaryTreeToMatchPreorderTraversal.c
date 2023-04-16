/**https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/ */
//You are given the root of a binary tree with n nodes, where each node is uniquely assigned a value from 1 to n. You are also given a sequence of n values voyage, which is the desired pre-order traversal of the binary tree.
//Any node in the binary tree can be flipped by swapping its left and right subtrees. For example, flipping node 1 will have the following effect:
//Flip the smallest number of nodes so that the pre-order traversal of the tree matches voyage.
//Return a list of the values of all flipped nodes. You may return the answer in any order. If it is impossible to flip the nodes in the tree to make the pre-order traversal match voyage, return the list [-1].


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
int* flipMatchVoyage(struct TreeNode* root, int* voyage, int voyageSize, int* returnSize){
    int* result = (int*)malloc(sizeof(int) * 1000);
    *returnSize = 0;
    int i = 0;
    struct TreeNode* stack[1000];
    int stackSize = 0;
    struct TreeNode* node = root;
    while(node != NULL || stackSize > 0){
        if(node != NULL){
            if(node->val != voyage[i]){
                result[0] = -1;
                *returnSize = 1;
                return result;
            }
            i++;
            if(node->left != NULL && node->left->val != voyage[i]){
                result[*returnSize] = node->val;
                (*returnSize)++;
                struct TreeNode* temp = node->left;
                node->left = node->right;
                node->right = temp;
            }
            stack[stackSize] = node;
            stackSize++;
            node = node->left;
        }else{
            stackSize--;
            node = stack[stackSize]->right;
        }
    }
    return result;

}

    