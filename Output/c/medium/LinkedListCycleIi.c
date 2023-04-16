/**https://leetcode.com/problems/linked-list-cycle-ii/ */
//Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
//There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.
//Do not modify the linked list.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if(head == NULL){
        return NULL;
    }
    struct ListNode* temp = head;
    struct ListNode* temp1 = head;
    while(temp != NULL && temp1 != NULL && temp1->next != NULL){
        temp = temp->next;
        temp1 = temp1->next->next;
        if(temp == temp1){
            break;
        }
    }
    if(temp == NULL || temp1 == NULL || temp1->next == NULL){
        return NULL;
    }
    temp = head;
    while(temp != temp1){
        temp = temp->next;
        temp1 = temp1->next;
    }
    return temp;
    
}

    