/**https://leetcode.com/problems/add-two-numbers-ii/ */
//You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* result = NULL;
    struct ListNode* temp = NULL;
    struct ListNode* prev = NULL;
    int carry = 0;
    int sum = 0;
    while(l1 != NULL || l2 != NULL){
        sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val = sum;
        temp->next = NULL;
        if(result == NULL){
            result = temp;
        }
        else{
            prev->next = temp;
        }
        prev = temp;
        if(l1){
            l1 = l1->next;
        }
        if(l2){
            l2 = l2->next;
        }
    }
    if(carry > 0){
        temp->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->next->val = carry;
        temp->next->next = NULL;
    }
    return result;


}

    