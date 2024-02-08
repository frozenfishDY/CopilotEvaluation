/**https://leetcode.com/problems/minimum-absolute-difference-in-bst/ */
//Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int getMinimumDifference(struct TreeNode* root){
    int min = INT_MAX;
    int prev = -1;
    struct TreeNode* curr = root;
    struct TreeNode* pre = NULL;
    while(curr != NULL){
        if(curr->left == NULL){
            if(prev != -1){
                int diff = curr->val - prev;
                if(diff < min){
                    min = diff;
                }
            }
            prev = curr->val;
            curr = curr->right;
        }else{
            pre = curr->left;
            while(pre->right != NULL && pre->right != curr){
                pre = pre->right;
            }
            if(pre->right == NULL){
                pre->right = curr;
                curr = curr->left;
            }else{
                pre->right = NULL;
                int diff = curr->val - prev;
                if(diff < min){
                    min = diff;
                }
                prev = curr->val;
                curr = curr->right;
            }
        }
    }
    return min;

}

    