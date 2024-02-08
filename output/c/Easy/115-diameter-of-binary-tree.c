/**https://leetcode.com/problems/diameter-of-binary-tree/ */
//Given the root of a binary tree, return the length of the diameter of the tree.
//The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
//The length of a path between two nodes is represented by the number of edges between them.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int diameterOfBinaryTree(struct TreeNode* root){
    int max = 0;
    int count = 0;
    int prev = 0;
    struct TreeNode* curr = root;
    struct TreeNode* pre = NULL;
    while(curr != NULL){
        if(curr->left == NULL){
            if(prev == curr->val){
                count++;
            }else{
                count = 1;
            }
            if(count > max){
                max = count;
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
                if(prev == curr->val){
                    count++;
                }else{
                    count = 1;
                }
                if(count > max){
                    max = count;
                }
                prev = curr->val;
                curr = curr->right;
            }
        }
    }
    return max;

}

    