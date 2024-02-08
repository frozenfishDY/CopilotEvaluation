/**https://leetcode.com/problems/sort-list/ */
//Given the head of a linked list, return the list after sorting it in ascending order.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* sortList(struct ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    struct ListNode* temp = head;
    struct ListNode* temp1 = head;
    struct ListNode* temp2 = head;
    while(temp1 != NULL && temp1->next != NULL){
        temp2 = temp;
        temp = temp->next;
        temp1 = temp1->next->next;
    }
    temp2->next = NULL;
    struct ListNode* left = sortList(head);
    struct ListNode* right = sortList(temp);
    struct ListNode* temp3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp3->next = NULL;
    struct ListNode* temp4 = temp3;
    while(left != NULL && right != NULL){
        if(left->val < right->val){
            temp4->next = left;
            left = left->next;
        }
        else{
            temp4->next = right;
            right = right->next;
        }
        temp4 = temp4->next;
    }
    if(left != NULL){
        temp4->next = left;
    }
    if(right != NULL){
        temp4->next = right;
    }
    return temp3->next;
    

}

    