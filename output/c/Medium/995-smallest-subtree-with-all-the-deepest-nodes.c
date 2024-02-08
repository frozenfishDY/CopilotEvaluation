/**https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/ */
//Given the root of a binary tree, the depth of each node is the shortest distance to the root.
//Return the smallest subtree such that it contains all the deepest nodes in the original tree.
//A node is called the deepest if it has the largest depth possible among any node in the entire tree.
//The subtree of a node is a tree consisting of that node, plus the set of all descendants of that node.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* subtreeWithAllDeepest(struct TreeNode* root){
    if(root == NULL){
        return NULL;
    }
    int left = 0;
    int right = 0;
    struct TreeNode* leftNode = root->left;
    struct TreeNode* rightNode = root->right;
    while(leftNode != NULL){
        left++;
        leftNode = leftNode->left;
    }
    while(rightNode != NULL){
        right++;
        rightNode = rightNode->right;
    }
    if(left == right){
        return root;
    }else if(left > right){
        return subtreeWithAllDeepest(root->left);
    }else{
        return subtreeWithAllDeepest(root->right);
    }

}

    