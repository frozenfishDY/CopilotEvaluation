/**https://leetcode.com/problems/remove-nodes-from-linked-list/ */
//You are given the head of a linked list.
//Remove every node which has a node with a strictly greater value anywhere to the right side of it.
//Return the head of the modified linked list.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNodes(struct ListNode* head){
    struct ListNode* result = NULL;
    struct ListNode* resultTail = NULL;
    struct ListNode* node = head;
    while(node != NULL){
        if(node->next == NULL || node->next->val <= node->val){
            if(result == NULL){
                result = node;
                resultTail = node;
            }else{
                resultTail->next = node;
                resultTail = node;
            }
        }
        node = node->next;
    }
    if(resultTail != NULL){
        resultTail->next = NULL;
    }
    return result;

}

    