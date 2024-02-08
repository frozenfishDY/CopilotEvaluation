/**https://leetcode.com/problems/count-good-nodes-in-binary-tree/ */
//Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.
//Return the number of good nodes in the binary tree.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int goodNodes(struct TreeNode* root){
    int i, j, k, count = 0;
    struct TreeNode *temp = root;
    while(temp != NULL){
        if(temp->val >= root->val){
            count++;
        }
        temp = temp->left;
    }
    temp = root;
    while(temp != NULL){
        if(temp->val >= root->val){
            count++;
        }
        temp = temp->right;
    }
    return count;

}

    