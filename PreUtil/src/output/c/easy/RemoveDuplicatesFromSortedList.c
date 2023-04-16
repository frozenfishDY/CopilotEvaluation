/**https://leetcode.com/problems/remove-duplicates-from-sorted-list/ */
//Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *p = head;
    while(p != NULL && p->next != NULL){
        if(p->val == p->next->val){
            p->next = p->next->next;
        }else{
            p = p->next;
        }
    }
    return head;

}
    