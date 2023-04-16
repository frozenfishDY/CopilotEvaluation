/**https://leetcode.com/problems/partition-list/ */
//Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
//You should preserve the original relative order of the nodes in each of the two partitions.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x){
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

    