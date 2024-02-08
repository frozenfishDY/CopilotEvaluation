/**https://leetcode.com/problems/kth-smallest-element-in-a-bst/ */
//Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int kthSmallest(struct TreeNode* root, int k){
    int left = 0;
    int right = 0;
    struct TreeNode* leftNode = root;
    struct TreeNode* rightNode = root;
    while(leftNode != NULL){
        left++;
        leftNode = leftNode->left;
    }
    while(rightNode != NULL){
        right++;
        rightNode = rightNode->right;
    }
    if(left == right){
        return (1 << left) - 1;
    }
    return 1 + kthSmallest(root->left, k) + kthSmallest(root->right, k);

}

    