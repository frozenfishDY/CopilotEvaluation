/**https://leetcode.com/problems/reverse-linked-list/ */
//Given the head of a singly linked list, reverse the list, and return the reversed list.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *p = head;
    struct ListNode *pre = NULL;
    while(p != NULL){
        struct ListNode *next = p->next;
        p->next = pre;
        pre = p;
        p = next;
    }
    return pre;

}
    