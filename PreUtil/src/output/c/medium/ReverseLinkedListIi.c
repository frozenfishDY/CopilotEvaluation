/**https://leetcode.com/problems/reverse-linked-list-ii/ */
//Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
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

    