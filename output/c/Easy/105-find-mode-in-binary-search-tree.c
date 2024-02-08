/**https://leetcode.com/problems/find-mode-in-binary-search-tree/ */
//Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.
//If the tree has more than one mode, return them in any order.
//Assume a BST is defined as follows:
//The left subtree of a node contains only nodes with keys less than or equal to the node's key.
//The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
//Both the left and right subtrees must also be binary search trees.


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
int* findMode(struct TreeNode* root, int* returnSize){
    int* ans = (int*)malloc(10000 * sizeof(int));
    *returnSize = 0;
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
                *returnSize = 0;
                ans[*returnSize] = curr->val;
                (*returnSize)++;
            }else if(count == max){
                ans[*returnSize] = curr->val;
                (*returnSize)++;
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
                    *returnSize = 0;
                    ans[*returnSize] = curr->val;
                    (*returnSize)++;
                }else if(count == max){
                    ans[*returnSize] = curr->val;
                    (*returnSize)++;
                }
                prev = curr->val;
                curr = curr->right;
            }
        }
    }
    return ans;

}

    