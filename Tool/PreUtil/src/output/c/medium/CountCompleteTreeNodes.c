/**https://leetcode.com/problems/count-complete-tree-nodes/ */
//Given the root of a complete binary tree, return the number of the nodes in the tree.
//According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
//Design an algorithm that runs in less than O(n) time complexity.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int countNodes(struct TreeNode* root){
    if(root == NULL){
        return 0;
    }
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
    return 1 + countNodes(root->left) + countNodes(root->right);

}

    