/**https://leetcode.com/problems/binary-tree-pruning/ */
//Given the root of a binary tree, return the same tree where every subtree (of the given tree) not containing a 1 has been removed.
//A subtree of a node node is node plus every node that is a descendant of node.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* pruneTree(struct TreeNode* root){
    if(root == NULL){
        return NULL;
    }
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if(root->val == 0 && root->left == NULL && root->right == NULL){
        return NULL;
    }
    return root;

}

    