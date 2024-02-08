/**https://leetcode.com/problems/remove-nth-node-from-end-of-list/ */
//Given the head of a linked list, remove the nth node from the end of the list and return its head.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* temp = head;
    struct ListNode* prev = NULL;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    if(count == n){
        head = head->next;
        return head;
    }
    temp = head;
    while(temp != NULL){
        if(count == n){
            prev->next = temp->next;
            return head;
        }
        count--;
        prev = temp;
        temp = temp->next;
    }
    return head;

}

    