/**https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/ */
//Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.
//A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxAncestorDiff(struct TreeNode* root){
    int max = 0;
    int min = 100000;
    int result = 0;
    if(root->left == NULL && root->right == NULL){
        return 0;
    }
    if(root->left != NULL){
        result = maxAncestorDiff(root->left);
        if(result > max){
            max = result;
        }
        if(root->left->val > max){
            max = root->left->val;
        }
        if(root->left->val < min){
            min = root->left->val;
        }
    }
    if(root->right != NULL){
        result = maxAncestorDiff(root->right);
        if(result > max){
            max = result;
        }
        if(root->right->val > max){
            max = root->right->val;
        }
        if(root->right->val < min){
            min = root->right->val;
        }
    }
    if(max - min > result){
        result = max - min;
    }
    return result;

}

    