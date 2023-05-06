/**https://leetcode.com/problems/remove-linked-list-elements/ */
//Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode *p = head;
    struct ListNode *pre = NULL;
    while(p != NULL){
        if(p->val == val){
            if(pre == NULL){
                head = p->next;
            }else{
                pre->next = p->next;
            }
            p = p->next;
        }else{
            pre = p;
            p = p->next;
        }
    }
    return head;

}
    