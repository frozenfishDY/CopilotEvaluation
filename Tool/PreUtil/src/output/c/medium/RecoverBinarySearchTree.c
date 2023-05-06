/**https://leetcode.com/problems/recover-binary-search-tree/ */
//You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void recoverTree(struct TreeNode* root){
    struct TreeNode* temp = root;
    struct TreeNode* prev = NULL;
    struct TreeNode* next = NULL;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    if(count == 1){
        return head;
    }
    temp = root;
    while(temp != NULL){
        if(count == 1){
            return head;
        }
        if(count % 2 == 0){
            next = temp->next;
            temp->next = prev;
            prev->next = next;
            if(count == 2){
                head = temp;
            }
            temp = next;
        }
        else{
            prev = temp;
            temp = temp->next;
        }
        count--;
    }
    return head;

}

    