/**https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/ */
//Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head){
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

    