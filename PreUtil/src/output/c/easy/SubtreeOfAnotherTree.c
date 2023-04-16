/**https://leetcode.com/problems/subtree-of-another-tree/ */
//Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.
//A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot){
    if(root == NULL){
        return false;
    }
    if(isSameTree(root, subRoot)){
        return true;
    }
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);

}

    