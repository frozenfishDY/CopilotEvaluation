/**https://leetcode.com/problems/reorder-list/ */
//You are given the head of a singly linked-list. The list can be represented as:
//L0 �� L1 �� �� �� Ln - 1 �� Ln
//Reorder the list to be on the following form:
//L0 �� Ln �� L1 �� Ln - 1 �� L2 �� Ln - 2 �� ��
//You may not modify the values in the list's nodes. Only nodes themselves may be changed.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head){
    if(head == NULL){
        return;
    }
    struct ListNode* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    if(count == 1){
        return;
    }
    int i = 0;
    temp = head;
    while(i < count / 2 - 1){
        temp = temp->next;
        i++;
    }
    struct ListNode* temp1 = temp->next;
    temp->next = NULL;
    temp = temp1;
    struct ListNode* temp2 = temp->next;
    temp->next = NULL;
    while(temp2 != NULL){
        temp1 = temp2->next;
        temp2->next = temp;
        temp = temp2;
        temp2 = temp1;
    }
    temp1 = head;
    while(temp != NULL){
        temp2 = temp1->next;
        temp1->next = temp;
        temp1 = temp2;
        temp2 = temp->next;
        temp->next = temp1;
        temp = temp2;
    }
    return;

}

    