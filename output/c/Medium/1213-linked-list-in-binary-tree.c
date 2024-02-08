/**https://leetcode.com/problems/linked-list-in-binary-tree/ */
//Given a binary tree root and a linked list with head as the first node. 
//Return True if all the elements in the linked list starting from the head correspond to some downward path connected in the binary tree otherwise return False.
//In this context downward path means a path that starts at some node and goes downwards.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSubPath(struct ListNode* head, struct TreeNode* root){
    if(head == NULL){
        return true;
    }
    if(root == NULL){
        return false;
    }
    if(head->val == root->val){
        if(isSubPath(head->next, root->left) || isSubPath(head->next, root->right)){
            return true;
        }
    }
    return isSubPath(head, root->left) || isSubPath(head, root->right);

}

    