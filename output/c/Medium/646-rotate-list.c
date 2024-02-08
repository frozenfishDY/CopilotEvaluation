/**https://leetcode.com/problems/rotate-list/ */
//Given the head of a linked list, rotate the list to the right by k places.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k){
    if(head == NULL){
        return NULL;
    }
    struct ListNode* temp = head;
    int len = 1;
    while(temp->next != NULL){
        temp = temp->next;
        len++;
    }
    temp->next = head;
    k = k % len;
    for(int i = 0; i < len - k; i++){
        temp = temp->next;
    }
    head = temp->next;
    temp->next = NULL;
    return head;

}

    