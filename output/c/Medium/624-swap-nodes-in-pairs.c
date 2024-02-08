/**https://leetcode.com/problems/swap-nodes-in-pairs/ */
//Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode* temp = head;
    struct ListNode* prev = NULL;
    struct ListNode* next = NULL;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    if(count == 1){
        return head;
    }
    temp = head;
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

    