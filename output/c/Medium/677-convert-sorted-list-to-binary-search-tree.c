/**https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/ */
//Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height-balanced binary search tree.


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
struct TreeNode* sortedListToBST(struct ListNode* head){
    if(head == NULL){
        return NULL;
    }
    struct ListNode* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    if(count == 1){
        struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        root->val = head->val;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    int i = 0;
    temp = head;
    while(i < count / 2 - 1){
        temp = temp->next;
        i++;
    }
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = temp->next->val;
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(temp->next->next);
    return root;

}

    